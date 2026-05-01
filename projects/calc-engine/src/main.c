#include <stdio.h>
#include <stdlib.h>

#include "../include/lexer.h"

void run_interactive_mode();

int main() {
    run_interactive_mode();

    return 0;
}


void run_interactive_mode() {
    char input[256];

    printf("calc> ");
    fgets(input, sizeof(input), stdin);

    Lexer lexer;
    lexer_init(&lexer, input);

    Token token;

    do {
        token = lexer_next_token(&lexer);
        printf("Token: %d, Value: %.2f\n", token.type, token.value);
    } while (token.type != TOKEN_EOF);
}
