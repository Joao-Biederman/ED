#include <iostream>
#include <cstdlib>
using namespace std;

class node {
private:
    char data;
    node *left;
    node *right;

public:
    node();
    node(char x);
    void setLeft(node *son);
    void setRight(node *son);
    void setData(char x);
    void createSon(node *son);
    void printData();
    void printTreePre();
    void printTreeIn();
    void printTreePos();
    char getdata();
    node *getLeft();
    node *getRight();
};

node::node()
{
    this->data = NULL;
    this->left = NULL;
    this->right = NULL;
}

node::node(char x) 
{
    this->data = x;
    this->left = NULL;
    this->right = NULL;
}

void node::setLeft(node *son)
{
    if (this->left == NULL)
    {
        this->left = son;
    } else
    {
        this->left->createSon(son);
    }
}

void node::setRight(node *son)
{
    if (this->right == NULL)
    {
        this->right = son;
    } else
    {
        this->right->createSon(son);
    }
}

void node::setData(char x)
{
    if (this->data == NULL)
    {
        this->data = x;
    } else
    {
        createSon(new node(x));
    }
}

void node::createSon(node *son)
{
    if (son->data > this->data)
    {
        this->setLeft(son);
    } else 
    {
        this->setRight(son);
    }    
}

void node::printData()
{
    printf("%c", this->data);
}

void node::printTreePre()
{
    if (this->left != NULL)
    {
        this->left->printTreePos();
    }

    if (this->right != NULL)
    {
        this->right->printTreePos();
    }

    this->printData();
    
}

void node::printTreeIn()
{
    if (this->left != NULL)
    {
        this->left->printTreePos();
    }

    if (this->right != NULL)
    {
        this->right->printTreePos();
    }

    this->printData();
    
}

void node::printTreePos()
{
    if (this->left != NULL)
    {
        this->left->printTreePos();
    }

    if (this->right != NULL)
    {
        this->right->printTreePos();
    }

    this->printData();
    
}

int main()
{
    int c, n; 
    char x[53];
    node tree;

    scanf("%d", &c);

    for (int i = 0; i < c; i++)
    {


    }        
        
    
}
