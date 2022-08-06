#include "node.h"
#include <iostream>

Add::Add(TreeNode *left, TreeNode *right)
{
    Add::left = left;
    Add::right = right;
}

int Add::eval()
{
    return Add::left->eval() + Add::right->eval();
}

void Add::print()
{
    std::cout << "(";
    Add::left->print();
    std::cout << "+";
    Add::right->print();
    std::cout << ")";
}

Subtract::Subtract(TreeNode *left, TreeNode *right)
{
    Subtract::left = left;
    Subtract::right = right;
}

int Subtract::eval()
{
    return Subtract::left->eval() - Subtract::right->eval();
}

void Subtract::print()
{
    std::cout << "(";
    Subtract::left->print();
    std::cout << "-";
    Subtract::right->print();
    std::cout << ")";
}

Multiply::Multiply(TreeNode *left, TreeNode *right)
{
    Multiply::left = left;
    Multiply::right = right;
}

int Multiply::eval()
{
    return Multiply::left->eval() * Multiply::right->eval();
}

void Multiply::print()
{
    std::cout << "(";
    Multiply::left->print();
    std::cout << "*";
    Multiply::right->print();
    std::cout << ")";
}

Divide::Divide(TreeNode *left, TreeNode *right)
{
    Divide::left = left;
    Divide::right = right;
}

int Divide::eval()
{
    return Divide::left->eval() / Divide::right->eval();
}

void Divide::print()
{
    std::cout << "(";
    Divide::left->print();
    std::cout << "/";
    Divide::right->print();
    std::cout << ")";
}

Negate::Negate(TreeNode *arg)
{
    Negate::arg = arg;
}

int Negate::eval()
{
    return -(Negate::arg->eval());
}

void Negate::print()
{
    std::cout << "-(";
    Negate::arg->print();
    std::cout << ")";
}

Integer::Integer(int val)
{
    Integer::val = val;
}

int Integer::eval()
{
    return Integer::val;
}

void Integer::print()
{
    std::cout << Integer::val;
}

Identifier::Identifier(std::string id, int val)
{
    Identifier::id = id;
    Identifier::val = val;
}

int Identifier::eval()
{
    return Identifier::val;
}

void Identifier::print()
{
    std::cout << Identifier::id;
}