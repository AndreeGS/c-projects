#include <stdio.h>
#include <stdlib.h>

void sort(int size, int *list);
void display(int size, int *list);

int main()
{
    int capacity = 2;
    int size = 0;

    int *numbers = malloc(capacity * sizeof(int));
    if (!numbers) {
        printf("Erro ao alocar memória!");
        return 1;
    }

    int value;

    printf("Informe os números (-1 para sair): ");

    while (1)
    {
        scanf("%d", &value);

        if (value == -1) {
            break;
        }

        if (size == capacity) {
            capacity *= 2;

            int *tmp = realloc(numbers, capacity * sizeof(int));
            if (!tmp) {
                printf("Erro ao realocar memória!\n");
                free(numbers);

                return 1;
            }

            numbers = tmp;
            printf("Capacidade aumentada para: %d\n", capacity);
        }

        numbers[size] = value;
        size++;
    }

    printf("Valores digitados: \n");
    display(size, numbers);

    printf("Valores digitados ordenados: \n");
    sort(size, numbers);
    display(size, numbers);

    printf("\n");

    free(numbers);

    return 0;
}

void display(int size, int *list)
{
    for (int i = 0; i < size; i++) {
        printf("%d \n", list[i]);
    }
}

void sort(int size, int *list) 
{
    for (int i = 0; i < size - 1; i++) {

        for (int j = 0; j < size - 1; j++) {
        
            if (list[j] > list[j+1]) {
                int tmp = list[j];

                list[j] = list[j + 1];

                list[j + 1] = tmp;
            }
        }
    }
}