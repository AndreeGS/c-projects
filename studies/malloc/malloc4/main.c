#include <stdio.h>
#include <stdlib.h>

int grow_array(int **arr, int *capacity);

int main() {
    int capacity = 2;

    int *memory = malloc(capacity * sizeof(int));
    if (!memory) {
        printf("Ocorreu um erro ao alocar memória!\n");
        return 1;
    }

    while (1) {
        if (!grow_array(&memory, &capacity)) {
            printf("Memória esgotada. Continuando com capacidade atual: %d\n", capacity);
            break;
        }

        for (int i = 0; i < capacity; i++)
            memory[i] = 42;

        printf("Capacidade: %d ints\n", capacity);
    }

    free(memory);
    return 0;
}

int grow_array(int **arr, int *capacity)
{
    int new_capacity = (*capacity) * 2;

    while (new_capacity > *capacity)
    {
        int *tmp = realloc(*arr, new_capacity * sizeof(int));

        if (tmp) {
            *arr = tmp;
            *capacity = new_capacity;
            return 1;
        }

        new_capacity = (*capacity + new_capacity) / 2;
    }

    return 0;
}
