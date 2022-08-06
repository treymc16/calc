#include "token.h"
#include "parser.h"
#include <string.h>
#include <iostream>

Parser::Parser(Scanner *s)
{
    Parser::s = s;
}

void Parser::scan_token()
{
    Parser::s->scan_token();
    Parser::next_token = Parser::s->next_token;
}

void Parser::parse()
{
    Parser::scan_token();
    do
    {
        auto tree = Parser::parse_expression();
        if (tree == NULL)
        {
            std::cout << "error could not evaluate expression" << std::endl;
            break;
        }
        else
        {
            std::cout << tree->eval() << std::endl;
        }
    } while (Parser::next_token.type != TokenType::END_OF_FILE);
}

TreeNode *Parser::parse_expression()
{
    auto *a = Parser::parse_term();
    if (a == NULL)
    {
        return NULL;
    }

    while (1)
    {
        if (Parser::next_token.type == TokenType::ADD)
        {
            Parser::scan_token();
            auto *b = Parser::parse_term();
            a = new Add(a, b);
        }
        else if (Parser::next_token.type == TokenType::NEGATE)
        {
            Parser::scan_token();
            auto *b = Parser::parse_term();
            a = new Subtract(a, b);
        }
        else
        {
            return a;
        }
    }
}

TreeNode *Parser::parse_term()
{
    auto *a = Parser::parse_factor();
    if (a == NULL)
    {
        return NULL;
    }

    while (1)
    {
        if (Parser::next_token.type == TokenType::MULTIPLY)
        {
            Parser::scan_token();
            auto *b = Parser::parse_factor();
            a = new Multiply(a, b);
        }
        else if (Parser::next_token.type == TokenType::DIVIDE)
        {
            Parser::scan_token();
            auto *b = Parser::parse_factor();
            a = new Divide(a, b);
        }
        else
        {
            return a;
        }
    }
}

TreeNode *Parser::parse_factor()
{
    if (Parser::next_token.type == TokenType::IDENTIFIER)
    {
        auto id = Parser::next_token.val;
        Parser::scan_token();
        if (Parser::next_token.type == TokenType::ASSIGN)
        {
            Parser::scan_token();
            auto a = Parser::parse_expression();
            if (a == NULL)
            {
                return NULL;
            }
            auto val = a->eval();
            if (Parser::vars.find(id) == Parser::vars.end())
            {
                Parser::vars.insert(std::pair<std::string, int>(id, val));
            }
            else
            {
                Parser::vars[id] = val;
            }
            auto temp = new Identifier(id, val);
            return temp;
        }
        else if (Parser::vars.find(id) != Parser::vars.end())
        {
            auto temp = new Integer(Parser::vars[id]);
            return temp;
        }
        return NULL;
    }
    else if (Parser::next_token.type == TokenType::NUM)
    {
        auto temp = new Integer(atoi((Parser::next_token.val).c_str()));
        Parser::scan_token();
        return temp;
    }
    else if (Parser::next_token.type == TokenType::LPAREN)
    {
        Parser::scan_token();
        auto a = Parser::parse_expression();
        if (a == NULL)
        {
            return NULL;
        }
        if (Parser::next_token.type == TokenType::RPAREN)
        {
            Parser::scan_token();
            return a;
        }
        else
        {
            return NULL;
        }
    }
    else if (Parser::next_token.type == TokenType::NEGATE)
    {
        Parser::scan_token();
        return new Negate(Parser::parse_factor());
    }
    else
    {
        return NULL;
    }
}
