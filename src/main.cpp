#include "scanner.h"
#include "parser.h"
#include <iostream>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        auto s = new Scanner(argv[1]);
        auto p = new Parser(s);
        p->parse();
        exit(EXIT_SUCCESS);
    }
    else
    {
        std::cout << "usage: calc [filename]" << std::endl;
        exit(EXIT_FAILURE);
    }
}