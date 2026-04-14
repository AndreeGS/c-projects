#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vault.h"
#include "../storage/storage.h"

#define INITIAL_CAPACITY 5

void vault_init(Vault *v)
{
    v->count = 0;
    v->capacity = INITIAL_CAPACITY;
    v->items = (Credential *) malloc(sizeof(Credential) * v->capacity);

    if (!v->items) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    load_vault(v);
}

void vault_add(Vault *v)
{
    if (v->count == v->capacity) {
        v->capacity *= 2;
        Credential *temp = realloc(v->items, sizeof(Credential) * v->capacity);

        if (!temp) {
            printf("Erro ao realocar memória.\n");
            exit(1);
        }

        v->items = temp;
    }

    Credential c;

    if (vault_find(v, c.service)) {
        printf("Serviço já cadastrado!\n");
        return;
    }

    printf("Serviço: ");
    scanf(" %[^\n]", c.service);

    printf("Usuário: ");
    scanf(" %[^\n]", c.username);

    printf("Senha: ");
    scanf(" %[^\n]", c.password);

    v->items[v->count++] = c;

    save_vault(v);

    printf("Credencial adicionada com sucesso!\n");
}

void vault_list(Vault *v)
{
    if (v->count == 0) {
        printf("Nenhuma credencial armazenada.\n");
        return;
    }

    printf("\n=== Credenciais ===\n");

    for (int i = 0; i < v->count; i++) {
        printf("\n[%d]\n", i + 1);
        printf("Serviço: %s\n", v->items[i].service);
        printf("Usuário: %s\n", v->items[i].username);
        printf("Senha: %s\n", v->items[i].password);
        printf("-------------------\n");
    }
}

void vault_delete(Vault *v)
{
    if (v->count == 0) {
        printf("Nenhuma credencial para remover.\n");
        return;
    }

    int index;

    printf("Digite o número da credencial a remover: ");
    scanf("%d", &index);

    if (index < 1 || index > v->count) {
        printf("Índice inválido.\n");
        return;
    }

    index--;

    for (int i = index; i < v->count - 1; i++) {
        v->items[i] = v->items[i + 1];
    }

    v->count--;

    save_vault(v);

    printf("Credencial removida com sucesso!\n");
}

Credential* vault_find(Vault *v, const char *service)
{
    for (int i = 0; i < v->count; i++) {
        if (strcmp(v->items[i].service, service) == 0) {
            return &v->items[i];
        }
    }
    
    return NULL;
}

void vault_exit(Vault *v)
{
    save_vault(v);
    vault_free(v);

    printf("Saindo...\n");
    exit(0);
}

void vault_free(Vault *v)
{
    free(v->items);
    v->items = NULL;
    v->count = 0;
    v->capacity = 0;
}
