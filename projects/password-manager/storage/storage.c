#include <stdio.h>
#include <stdlib.h>

#include "storage.h"
#include "../crypto/crypto.h"
#include "../vault/vault.h"

#define FILE_NAME "vault.dat"

void save_vault(Vault *v)
{
    FILE *file = fopen(FILE_NAME, "wb");

    if (!file) {
        printf("Erro ao salvar o vault.\n");
        return;
    }

    for (int i = 0; i < v->count; i++) {
        crypto_encrypt_credential(&v->items[i]);
    }

    fwrite(&v->count, sizeof(int), 1, file);
    fwrite(v->items, sizeof(Credential), v->count, file);

    fclose(file);

    for (int i = 0; i < v->count; i++) {
        crypto_decrypt_credential(&v->items[i]);
    }

    printf("Vault salvo com sucesso!\n");
}

void load_vault(Vault *v)
{
    FILE *file = fopen(FILE_NAME, "rb");

    if (!file) {
        printf("Nenhum arquivo encontrado. Vault iniciando vazio.\n");
        return;
    }

    int count;

    fread(&count, sizeof(int), 1, file);

    if (count > v->capacity) {
        v->capacity = count;

        Credential *temp = realloc(v->items, sizeof(Credential) * v->capacity);

        if (!temp) {
            printf("Erro ao alocar memória.\n");
            fclose(file);
            return;
        }

        v->items = temp;
    }

    fread(v->items, sizeof(Credential), count, file);

    for (int i = 0; i < count; i++) {
        crypto_decrypt_credential(&v->items[i]);
    }

    v->count = count;

    fclose(file);

    printf("Vault carregado com sucesso!\n");
}