#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include <iostream>
#include <string>

using namespace std;

#include "node.h"
#include "doubly_linked_list_exception.h"

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
    
    void  insertFirst(int value);
    void  insertLast(int value);
    void  insertAfterValue(int newValue, int value);
    void  insertAfterID(int newValue, int id);

    void  deleteFirst();
    void  deleteLast();
    void  deleteByValue(int value);
    void  deleteByID(int id);

    string  displayForward();
    string  displayBackward();
};

#endif