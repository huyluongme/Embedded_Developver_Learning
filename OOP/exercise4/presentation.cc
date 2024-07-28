#include <iostream>

using namespace std;

#include "presentation.h"

Presentation::Presentation()
    : m_loop(true)
{
    this->m_pDLL = new DoublyLinkedList();
}

Presentation::~Presentation()
{
}

// system("/bin/bash -c 'read'") is for Linux. In Window Environment, replace it by using system("pause")
void Presentation::pressEnterKeyToContinue() {
    cout << "\nPress Enter to continue..." << std::flush;
    system("/bin/bash -c 'read'");
}

void Presentation::printMenu()
{
    cout << "=======================\n";
    cout << "Doubly Linked List Menu\n";
    cout << "=======================\n";
    cout << "1 - Add a new item\n";
    cout << "2 - Delete an item\n";
    cout << "3 - Show number of items\n";
    cout << "4 - Find max item\n";
    cout << "5 - Find min item\n";
    cout << "6 - Find item\n";
    cout << "7 - Print all items - Forward\n";
    cout << "8 - Print all items - Backward\n";
    cout << "9 - Exit\n";
    cout << "Please enter your choice: ";
}

void Presentation::addItem()
{
    int value, pos;
    cout << "Which position in array do you want to add (Head: 1, Tail: 2, After a Value: 3): ";
    cin >> pos;
    cout << "Enter the value: ";
    cin >> value;
    switch (pos)
    {
    case 1:
        cout << this->m_pDLL->insertFirst(value) << '\n';
        break;
    case 2:
        cout << this->m_pDLL->insertLast(value) << '\n';
        break;
    case 3:
        int targetValue;
        cout << "Please enter target value: ";
        cin >> targetValue;
        cout << this->m_pDLL->insertAfterValue(value, targetValue) << '\n';
        break;
    default:
        break;
    }
}

void Presentation::deleteItem()
{
    int value, pos;
    cout << "Which item in array do you want to delete (Head: 1, Tail: 2, By Value: 3): ";
    cin >> pos;
    switch (pos)
    {
    case 1:
        this->m_pDLL->deleteFirst();
        break;
    case 2:
        this->m_pDLL->deleteLast();
        break;
    case 3:
        cout << "Enter the value: ";
        cin >> value;
        this->m_pDLL->deleteByValue(value);
        break;
    default:
        break;
    }
}

void Presentation::findItem()
{
    int value;
    cout << "Enter value: ";
    cin >> value;
    if(this->m_pDLL->search(value)) cout << "Item is exist\n"; 
    else cout << "Item isn't exist\n";
}

bool Presentation::process()
{
    cin >> this->m_choice;
    switch (this->m_choice)
    {
    case 1:
        this->addItem();
        break;
    case 2:
        this->deleteItem();
        break;
    case 3: 
        cout << "Number of items: " << this->m_pDLL->getNumOfElements() << '\n';
        break;
    case 4:
        cout << "Max item: " << this->m_pDLL->findMax() << '\n';
        break;
    case 5:
        cout << "Min item: " << this->m_pDLL->findMin() << '\n';
        break;
    case 6:
        this->findItem();
        break;
    case 7:
        cout << "Forward: " << this->m_pDLL->displayForward() << '\n';
        break;
    case 8:
        cout << "Backward: " << this->m_pDLL->displayBackward() << '\n';
        break;
    case 9:
        return false;
    default:
        cout << "Invalid choice. Please enter valid number!\n";
        break;
    }
    this->pressEnterKeyToContinue();
    system("clear");
    return true;
}

void Presentation::run()
{
    while (this->m_loop)
    {
        this->printMenu();
        this->m_loop = this->process();
    }
    delete this->m_pDLL;
}