#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int capacity = 8;
    int size = 0;
    int c;

    char *nome = malloc(capacity);
    if (!nome) {
        printf("Erro ao alocar memória");

        return 1;
    }

    printf("Digite algo: ");

    while((c = getchar()) != '\n') {
        if (size + 1 >= capacity) {
            capacity *= 2;

            char *tmp = realloc(nome, capacity);
            if (!tmp) {
                printf("Erro ao realocar memória");
                free(nome);
                return 1;
            }

            nome = tmp;
        }
      
        nome[size] = c;
        size++;
    }

    nome[size] = '\0';

    char *nome2 = malloc(strlen(nome) + 1);
    strcpy(nome2, nome);

    printf("Nome na variavel 2: %s", nome2);

    printf("\n");
 
    return 0;
}
