#ifndef LEXER_H
#define LEXER_H

typedef enum {
    TOKEN_NUMBER,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_STAR,
    TOKEN_SLASH,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_EOF,
    TOKEN_INVALID
} TokenType;

typedef struct {
    TokenType type;
    double value;
} Token;

typedef struct {
    const char *src;
    int pos;
    char current;
} Lexer;

void lexer_init(Lexer *lexer, const char *src);
Token lexer_next_token(Lexer *lexer);

#endif
