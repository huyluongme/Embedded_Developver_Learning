#ifndef NODE_H
#define NODE_H

class Node
{
private:
    int m_value;
    Node* m_pLeft;
    Node* m_pRight;
public:
    Node(int value, Node* left, Node* right);
    ~Node();
    
    int     getData();
    Node*   getLeft();
    Node*   getRight();

    void    setLeft(Node* newLeft);
    void    setRight(Node* newRight);
};

#endif