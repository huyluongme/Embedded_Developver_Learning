#ifndef PRESENTATION_H
#define PRESENTATION_H

#include "doubly_linked_list.h"

class Presentation
{
private:
    int m_choice;
    bool m_loop;
    DoublyLinkedList* m_pDLL;
public:
    Presentation();
    
    void pressEnterKeyToContinue();
    void printMenu();
    void addItem();
    void deleteItem();
    void findItem();
    bool process();
    void run();

    ~Presentation();
};

#endif