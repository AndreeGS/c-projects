#include <stdio.h>
#include <stdlib.h>

#include "vault/vault.h"

void menu();

int main()
{
    Vault vault;
    vault_init(&vault);

    int choice;

    do {
        menu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            vault_add(&vault);
            break;
        case 2:
            vault_list(&vault);
            break;
        case 3:
            vault_delete(&vault);
            break;
        case 4:
            vault_exit(&vault);
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }
    } while (choice !=4);

    vault_free(&vault);
    return 0;
}

void menu() {
    // Cores ANSI
    const char *reset = "\033[0m";
    const char *blue = "\033[1;34m";
    const char *green = "\033[1;32m";
    const char *yellow = "\033[1;33m";
    const char *red = "\033[1;31m";

    printf("\n%s==============================%s\n", blue, reset);
    printf("%s       PASSWORD MANAGER       %s\n", green, reset);
    printf("%s==============================%s\n", blue, reset);

    printf("%s1.%s Adicionar Credencial\n", yellow, reset);
    printf("%s2.%s Listar Credenciais\n", yellow, reset);
    printf("%s3.%s Remover Credencial\n", yellow, reset);
    printf("%s4.%s Sair\n", red, reset);

    printf("%sEscolha uma opção: %s", green, reset);
}
