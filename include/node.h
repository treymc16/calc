
#include "token.h"
class TreeNode
{
public:
    TreeNode() {}
    virtual int eval() = 0;
    virtual void print() = 0;
};

class Add : public TreeNode
{
public:
    int eval();
    void print();
    Add(TreeNode *left, TreeNode *right);
    TreeNode *left;
    TreeNode *right;
};

class Subtract : public TreeNode
{
public:
    int eval();
    void print();
    Subtract(TreeNode *left, TreeNode *right);
    TreeNode *left;
    TreeNode *right;
};

class Multiply : public TreeNode
{
public:
    int eval();
    void print();
    Multiply(TreeNode *left, TreeNode *right);
    TreeNode *left;
    TreeNode *right;
};

class Divide : public TreeNode
{
public:
    int eval();
    void print();
    Divide(TreeNode *left, TreeNode *right);
    TreeNode *left;
    TreeNode *right;
};

class Negate : public TreeNode
{
public:
    int eval();
    void print();
    Negate(TreeNode *arg);
    TreeNode *arg;
};

class Integer : public TreeNode
{
public:
    int eval();
    void print();
    Integer(int val);
    int val;
};

class Identifier : public TreeNode
{
public:
    int eval();
    void print();
    Identifier(std::string id, int val);
    std::string id;
    int val;
};