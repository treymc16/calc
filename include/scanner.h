#ifndef SCANNER_H
#define SCANNER_H
#include "token.h"
#include <stdio.h>
#define BUFF_SIZE 1024
class Scanner
{
public:
    Token next_token;
    bool done;
    void scan_token();
    void load_line();
    char next();
    char peek();
    Scanner(const char *filename);
    ~Scanner();

private:
    FILE *fp;
    std::string filename;
    std::string input;
    char buffer[BUFF_SIZE];
    int pos;
};

bool is_digit(char c);
bool is_space(char c);
bool is_letter(char c);
bool is_alphanum(char c);
bool is_newline(char c);
#endif