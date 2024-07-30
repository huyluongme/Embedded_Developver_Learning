#ifndef PRESENTATION_H
#define PRESENTATION_H

#include "doubly_linked_list.h"

class DoublyLinkedListApp
{
private:
    int m_choice;
    bool m_loop;
    DoublyLinkedList* m_pDLL;
public:
    DoublyLinkedListApp();
    
    void pressEnterKeyToContinue();
    void printMenu();
    void addItem();
    void deleteItem();
    void findItem();
    bool process();
    void run();

    ~DoublyLinkedListApp();
};

#endif