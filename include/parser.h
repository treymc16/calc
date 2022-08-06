#ifndef PARSER_H
#define PARSER_H
#include "token.h"
#include "node.h"
#include "scanner.h"
#include <map>
class Parser
{
public:
    Parser(Scanner *s);
    void parse();
    TreeNode *parse_expression();
    TreeNode *parse_term();
    TreeNode *parse_factor();
    void scan_token();
    std::map<std::string, int> vars;
    Token next_token;
    Scanner *s;
};
#endif