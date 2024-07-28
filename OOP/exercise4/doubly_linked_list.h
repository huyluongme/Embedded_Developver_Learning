#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include <iostream>
#include <string>

using namespace std;

#include "node.h"

class DoublyLinkedList
{
private:
    Node* m_pFirstNode;
    Node* m_pLastNode;
    int m_numOfElements;
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    bool    isEmpty();
    Node*   search(int value);
    int     getNumOfElements();
    int     findMax();
    int     findMin();
    
    string  insertFirst(int value);
    string  insertLast(int value);
    string  insertAfterValue(int newValue, int value);

    string  deleteFirst();
    string  deleteLast();
    string  deleteByValue(int value);

    string  displayForward();
    string  displayBackward();
};

#endif