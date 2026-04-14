#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int n, i;

    printf("Informe a quantidade de números: ");
    scanf("%d", &n);

    int *numbers = malloc(n * sizeof(int)); 

    for (i = 0; i < n; i++) {
        numbers[i] = i;
    }

    for (i = 0; i < n; i++) {
        printf("Valor na posição %d: %d\n", i, numbers[i]);
    }

    free(numbers);

    return 0;
}