#include "scanner.h"
#include <iostream>
#include "token.h"

Scanner::Scanner(const char *filename)
{
    Scanner::filename = filename;
    Scanner::pos = 0;
    Scanner::done = false;
    Scanner::fp = fopen(filename, "r");
    if (Scanner::fp == NULL)
    {
        std::cout << "Failed to open file: " << filename << std::endl;
        exit(EXIT_FAILURE);
    }
}

Scanner::~Scanner()
{
    fclose(Scanner::fp);
}

void Scanner::load_line()
{
    Scanner::pos = 0;
    std::fill_n(Scanner::buffer, BUFF_SIZE, '\0');
    Scanner::input.clear();
    int c;
    int i = 0;
    while (1)
    {
        c = fgetc(Scanner::fp);
        if (feof(Scanner::fp))
        {
            Scanner::done = true;
            break;
        }
        if (c != '\r')
        {
            Scanner::buffer[i++] = c;
        }
        if (c == '\n')
        {
            break;
        }

        Scanner::input = Scanner::buffer;
    }
}

void Scanner::scan_token()
{
    if (!Scanner::done && Scanner::pos == Scanner::input.length())
    {
        Scanner::load_line();
    }

    Scanner::next_token = Token{TokenType::END_OF_FILE, "EOF"};

    char c = Scanner::next();
    while (is_space(c))
    {
        c = Scanner::next();
    }
    if (is_digit(c))
    {
        std::string num{c};
        while (is_digit(Scanner::peek()))
        {
            num.push_back(Scanner::next());
        }
        Scanner::next_token = Token{TokenType::NUM, num};
    }
    else if (is_letter(c))
    {
        std::string id{c};
        while (is_alphanum(Scanner::peek()))
        {
            id.push_back(Scanner::next());
        }
        Scanner::next_token = Token{TokenType::IDENTIFIER, id};
    }
    else if (is_newline(c))
    {
        Scanner::next_token = Token{TokenType::NEW_LINE, "\n"};
    }
    else
    {
        switch (c)
        {
        case '+':
            Scanner::next_token = Token{TokenType::ADD, "+"};
            break;
        case '-':
            Scanner::next_token = Token{TokenType::NEGATE, "-"};
            break;
        case '*':
            Scanner::next_token = Token{TokenType::MULTIPLY, "*"};
            break;
        case '/':
            Scanner::next_token = Token{TokenType::DIVIDE, "/"};
            break;
        case '(':
            Scanner::next_token = Token{TokenType::LPAREN, "("};
            break;
        case ')':
            Scanner::next_token = Token{TokenType::RPAREN, ")"};
            break;
        case '=':
            Scanner::next_token = Token{TokenType::ASSIGN, "="};
            break;
        }
    }
}

char Scanner::next()
{
    return Scanner::buffer[Scanner::pos++];
}

char Scanner::peek()
{
    return Scanner::buffer[Scanner::pos];
}

bool is_digit(char c)
{
    return c >= 48 && c <= 57;
}

bool is_letter(char c)
{
    return (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
}

bool is_alphanum(char c)
{
    return c == '_' || is_digit(c) || is_letter(c);
}

bool is_space(char c)
{
    return c == ' ' || c == '\t';
}

bool is_newline(char c)
{
    return c == '\n' || c == '\r';
}