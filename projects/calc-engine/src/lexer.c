#include "../include/lexer.h"
#include <ctype.h>
#include <stdlib.h>

void lexer_advance(Lexer *lexer) {
    lexer->pos++;
    lexer->current = lexer->src[lexer->pos];
}

void lexer_skip_whitespace(Lexer *lexer) {
    while (lexer->current == ' ' || lexer->current == '\t' || lexer->current == '\n') {
        lexer_advance(lexer);
    }
}

double lexer_read_number(Lexer *lexer) {
    char buffer[64];
    int i = 0;

    while (isdigit(lexer->current) || lexer->current == '.') {
        buffer[i++] = lexer->current;
        lexer_advance(lexer);
    }

    buffer[i] = '\0';
    return atof(buffer);
}

void lexer_init(Lexer *lexer, const char *src) {
    lexer->src = src;
    lexer->pos = 0;
    lexer->current = src[0];
}

Token lexer_next_token(Lexer *lexer) {
    Token token;

    while (lexer->current != '\0') {

        if (isspace(lexer->current)) {
            lexer_skip_whitespace(lexer);
            continue;
        }

        if (isdigit(lexer->current)) {
            token.type = TOKEN_NUMBER;
            token.value = lexer_read_number(lexer);
            return token;
        }

        switch (lexer->current) {
            case '+':
                lexer_advance(lexer);
                token.type = TOKEN_PLUS;
                return token;
            case '-':
                lexer_advance(lexer);
                token.type = TOKEN_MINUS;
                return token;
            case '*':
                lexer_advance(lexer);
                token.type = TOKEN_STAR;
                return token;
            case '/':
                lexer_advance(lexer);
                token.type = TOKEN_SLASH;
                return token;
            case '(':
                lexer_advance(lexer);
                token.type = TOKEN_LPAREN;
                return token;
            case ')':
                lexer_advance(lexer);
                token.type = TOKEN_RPAREN;
                return token;
            default:
                lexer_advance(lexer);
                token.type = TOKEN_INVALID;
                return token;
        }
    }

    token.type = TOKEN_EOF;
    return token;
}
