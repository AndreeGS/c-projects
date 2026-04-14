#include <stdio.h>
#include <stdlib.h>

int main()
{
    int capacity = 8;
    int size = 0;

    char *text = malloc(capacity);
    if (!text) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    printf("Insira o texto: \n");

    int c;
    while ((c = getchar()) != '\n') {

        if (size + 1 >= capacity) {
            capacity *= 2;

            char *tmp = realloc(text, capacity);
            if (!tmp) {
                printf("Erro ao realocar memória!\n");
                free(text);
                return 1;
            }

            text = tmp;
            printf("Memória realocada! Capacidade: %d\n", capacity);
        }

        text[size] = c;
        size++;
    }

    text[size] = '\0';

    printf("\nTexto digitado: %s\n", text);

    free(text);
    return 0;
}
