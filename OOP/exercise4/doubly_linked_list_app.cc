#include <iostream>

using namespace std;

#include "doubly_linked_list_app.h"

DoublyLinkedListApp::DoublyLinkedListApp()
    : m_loop(true)
{
    this->m_pDLL = new DoublyLinkedList();
}

DoublyLinkedListApp::~DoublyLinkedListApp()
{
}

// system("/bin/bash -c 'read'") is for Linux. In Window Environment, replace it by using system("pause")
void DoublyLinkedListApp::pressEnterKeyToContinue() {
    cout << "\nPress Enter to continue..." << std::flush;
    system("/bin/bash -c 'read'");
}

void DoublyLinkedListApp::printMenu()
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

void DoublyLinkedListApp::addItem()
{
    int value, pos;
    cout << "Which position in array do you want to add (Head: 1, Tail: 2, After a Value: 3, After ID: 4): ";
    cin >> pos;
    cout << "Enter the value: ";
    cin >> value;
    switch (pos)
    {
    case 1:
        this->m_pDLL->insertFirst(value);
        cout << "Item is added.\n";
        break;
    case 2:
        this->m_pDLL->insertLast(value);
        cout << "Item is added.\n";
        break;
    case 3:
        int targetValue;
        cout << "Please enter target value: ";
        cin >> targetValue;
        try
        {
            this->m_pDLL->insertAfterValue(value, targetValue);
            cout << "Item is added.\n";
        }
        catch(const TargetValueIsNotExist& e)
        {
            std::cerr << e.what() << '\n';
        }
        break;
    case 4:
        int id;
        cout << "Please enter id: ";
        cin >> id;
        try
        {
            this->m_pDLL->insertAfterID(value, id);
            cout << "Item is added.\n";
        }
        catch(const ListIsEmpty& e)
        {
            std::cerr << e.what() << '\n';
        }
        catch(const IDInvalid& e)
        {
            std::cerr << e.what() << '\n';
        }
        break;
    default:
        break;
    }
}

void DoublyLinkedListApp::deleteItem()
{
    int value, pos, id;
    cout << "Which item in array do you want to delete (Head: 1, Tail: 2, By Value: 3, By ID: 4): ";
    cin >> pos;
    switch (pos)
    {
    case 1:
        try
        {
            this->m_pDLL->deleteFirst();
            cout << "Item is deleted.\n";
        }
        catch(const ListIsEmpty& e)
        {
            std::cerr << e.what() << '\n';
        }
        break;
    case 2:
        try
        {
            this->m_pDLL->deleteLast();
            cout << "Item is deleted.\n";
        }
        catch(const ListIsEmpty& e)
        {
            std::cerr << e.what() << '\n';
        }
        break;
    case 3:
        cout << "Enter the value: ";
        cin >> value;
        try
        {
            this->m_pDLL->deleteByValue(value);
            cout << "Item is deleted.\n";
        }
        catch(const ListIsEmpty& e)
        {
            std::cerr << e.what() << '\n';
        }
        catch(const ItemNotExist& e)
        {
            std::cerr << e.what() << '\n';
        }
        break;
    case 4:
        cout << "Enter the ID: ";
        cin >> id;
        try
        {
            this->m_pDLL->deleteByID(id);
            cout << "Item is deleted.\n";
        }
        catch(const ListIsEmpty& e)
        {
            std::cerr << e.what() << '\n';
        }
        catch(const IDInvalid& e)
        {
            std::cerr << e.what() << '\n';
        }
        break;
    default:
        break;
    }
}

void DoublyLinkedListApp::findItem()
{
    int value;
    cout << "Enter value: ";
    cin >> value;
    if(this->m_pDLL->search(value)) cout << "Item is exist\n"; 
    else cout << "Item isn't exist\n";
}

bool DoublyLinkedListApp::process()
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
        try
        {
            string res = this->m_pDLL->displayForward();
            cout << "Forward: " << res << '\n';
        }
        catch(const ListIsEmpty& e)
        {
            std::cerr << e.what() << '\n';
        }
        break;
    case 8:
        try
        {
            string res = this->m_pDLL->displayBackward();
            cout << "Backward: " << res << '\n';
        }
        catch(const ListIsEmpty& e)
        {
            std::cerr << e.what() << '\n';
        }
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

void DoublyLinkedListApp::run()
{
    while (this->m_loop)
    {
        this->printMenu();
        this->m_loop = this->process();
    }
    delete this->m_pDLL;
}