#include <stdio.h>
#include <stdlib.h>

/*
    Retorna um ponteiro para a região de  memória alocada ou null.
*/

int main() 
{
    int *x;

    x = malloc(sizeof(int));
    
    if (x == NULL) {
        printf("Ocorreu um erro ao alocar memória!");

        return 0;
    }

    *x = 63;

    printf("Valor alocado: %d\n", *x);
    printf("Endereço alocado: %p\n", x);

    free(x);
    printf("Memória liberada!\n");

    return 0;
}