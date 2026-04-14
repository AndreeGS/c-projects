#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_line();
char *remove_vowels(const char *text);
char *invert_word(const char *text);

int main()
{
    printf("Digite uma palavra: ");

    char *text = read_line();

    char *stringWithoutVowels = remove_vowels(text);

    printf("Palavra sem vogais: %s", stringWithoutVowels);
    printf("\n");

    char *stringReversed = invert_word(text);

    printf("Palavra invertida: %s", stringReversed);
    printf("\n");

    free(text);
    free(stringWithoutVowels);

    return 0;
}

char *invert_word(const char *text)
{
    int len = strlen(text);
    char *string = malloc(len + 1);
    if (!string) return NULL;

    for (int i = len - 1; i >= 0; i-- ) {
        string[i] = text[len - 1 - i];
    }

    string[len] = '\0';

    return string;
}

char *remove_vowels(const char *text)
{
    int len = strlen(text);
    char *string = malloc(len + 1);
    
    int j = 0;

    for (int i = 0; i < len; i++) {
        char c = text[i];

        if (c!='a' && c!='e' && c!='i' && c!='o' && c!='u' &&
            c!='A' && c!='E' && c!='I' && c!='O' && c!='U'
        ) {
            string[j++] = c;
        }
    }

    string[j] = '\0';

    char *tmp = realloc(string, j + 1);
    if (tmp) string = tmp;

    return string;
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
