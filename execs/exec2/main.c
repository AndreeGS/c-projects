#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(const char *a, const char *b);
char *read_line();

int main()
{
    printf("Digite a primeira string: ");
    char *string1 = read_line();

    printf("Digite a segunda string: ");
    char *string2 = read_line();

    char *strConcat = concat(string1, string2);

    printf("String Concatenada: %s\n", strConcat);

    free(string1);
    free(string2);
    free(strConcat);

    return 0;
}

char *concat(const char *a, const char *b)
{
    int tam = strlen(a) + strlen(b) + 1;

    char *stringConcat = malloc(tam);
    if (!stringConcat) return NULL;

    strcpy(stringConcat, a);
    strcat(stringConcat, b);
    
    return stringConcat;
}

char *read_line()
{
    int size = 0;
    int capacity = 8;
    int c;

    char *string = malloc(capacity);
    if (!string) return NULL;

    while((c = getchar()) != '\n' && c != EOF) {
        if (size >= capacity - 1) {
            capacity = capacity * 2;

            char *tmp = realloc(string, capacity);
            if (!tmp) {
                printf("Erro ao realocar memória!");
                free(string);
                return NULL;
            }

            string = tmp;
        }

        string[size++] = c;
    }

    string[size] = '\0';

    return string;
}