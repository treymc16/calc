#ifndef TOKEN_H
#define TOKEN_H
#include <string>

typedef enum TokenType
{
    LPAREN,
    RPAREN,
    ADD,
    NEGATE,
    DIVIDE,
    MULTIPLY,
    ASSIGN,
    NUM,
    IDENTIFIER,
    NEW_LINE,
    SPACE,
    END_OF_FILE,
} TokenType;

typedef struct Token
{
    TokenType type;
    std::string val;

} Token;
#endif