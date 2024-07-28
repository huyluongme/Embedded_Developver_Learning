#include "node.h"

Node::Node(int value, Node* left, Node* right)
    : m_value(value), m_pLeft(left), m_pRight(right)
{
}

Node::~Node()
{
}

int Node::getData()
{
    return this->m_value;
}

Node* Node::getLeft()
{
    return this->m_pLeft;
}

Node* Node::getRight()
{
    return this->m_pRight;
}

void Node::setLeft(Node* newLeft)
{
    this->m_pLeft = newLeft;
}

void Node::setRight(Node* newRight)
{
    this->m_pRight = newRight;
}