#include <iostream>

using namespace std;

#include "doubly_linked_list.h"

DoublyLinkedList::DoublyLinkedList()
    : m_pFirstNode(nullptr), m_pLastNode(nullptr), m_numOfElements(0)
{
}

DoublyLinkedList::~DoublyLinkedList()
{
    Node* tmp = this->m_pFirstNode;
    while (tmp)
    {
        Node* nextNode = tmp->getRight();
        delete tmp;
        tmp = nextNode;
    }
}

bool DoublyLinkedList::isEmpty()
{
    return this->m_numOfElements == 0;
}

Node* DoublyLinkedList::search(int value)
{
    Node* res = this->m_pFirstNode;
    while (res)
    {
        if(res->getData() == value) { break; }
        res = res->getRight();
    }
    
    return res;
}

int DoublyLinkedList::getNumOfElements()
{
    return this->m_numOfElements;
}

int DoublyLinkedList::findMax()
{
    int res = this->m_pFirstNode->getData();
    Node* tmp = this->m_pFirstNode->getRight();
    while (tmp)
    {
        if(res < tmp->getData())
        {
            res = tmp->getData();
        }
        tmp = tmp->getRight();
    }
    return res;
}

int DoublyLinkedList::findMin()
{
    int res = this->m_pFirstNode->getData();
    Node* tmp = this->m_pFirstNode->getRight();
    while (tmp)
    {
        if(res > tmp->getData())
        {
            res = tmp->getData();
        }
        tmp = tmp->getRight();
    }
    return res;
}

string DoublyLinkedList::insertFirst(int value)
{
    Node* newNode = new Node(value, nullptr, nullptr);
    if(this->isEmpty())
    {
        this->m_pFirstNode = newNode;
        this->m_pLastNode = newNode;
    }
    else
    {
        this->m_pFirstNode->setLeft(newNode);
        newNode->setRight(this->m_pFirstNode);
        this->m_pFirstNode = newNode;
    }
    this->m_numOfElements += 1;
    return "Item is added";
}

string DoublyLinkedList::insertLast(int value)
{
    Node* newNode = new Node(value, nullptr, nullptr);
    if(this->isEmpty())
    {
        this->m_pFirstNode = newNode;
        this->m_pLastNode = newNode;
    }
    else
    {
        this->m_pLastNode->setRight(newNode);
        newNode->setLeft(this->m_pLastNode);
        this->m_pLastNode = newNode;
    }
    this->m_numOfElements += 1;
    return "Item is added";
}

string DoublyLinkedList::insertAfterValue(int newValue, int targetValue)
{
    string res = "";
    Node* searchNode = this->search(targetValue);
    if(searchNode)
    {
        Node* newNode = new Node(newValue, nullptr, nullptr);
        if(searchNode->getRight() == nullptr){
            res = this->insertLast(newValue);
        }
        else
        {
            Node* nextNodeOfSeachNode = searchNode->getRight();
            searchNode->setRight(newNode);
            nextNodeOfSeachNode->setLeft(newNode);
            newNode->setLeft(searchNode);
            newNode->setRight(nextNodeOfSeachNode);
            this->m_numOfElements += 1;
            res = "Item is added";
        }
    }
    else
    {
        res = "Target value is not exist";
    }
    return res;
}

string DoublyLinkedList::deleteFirst()
{
    string res = "";
    if(!this->isEmpty())
    {
        Node* tmp = this->m_pFirstNode;
        if(this->m_numOfElements == 1)
        {
            this->m_pFirstNode = nullptr;
            this->m_pLastNode = nullptr;
        }
        else
        {
            this->m_pFirstNode = this->m_pFirstNode->getRight();
            this->m_pFirstNode->setLeft(nullptr);
        }
        delete tmp;
        this->m_numOfElements -= 1;
        res = "Item is deleted";
    }
    else
    {
        res = "List is empty";
    }
    return res;
}

string DoublyLinkedList::deleteLast()
{
    string res = "";
    if(!this->isEmpty())
    {
        Node* tmp = this->m_pLastNode;
        if(this->m_numOfElements == 1)
        {
            this->m_pFirstNode = nullptr;
            this->m_pLastNode = nullptr;
        }
        else
        {
            this->m_pLastNode = this->m_pLastNode->getLeft();
            this->m_pLastNode->setRight(nullptr);
        }
        delete tmp;
        this->m_numOfElements -= 1;
        res = "Item is deleted";
    }
    else
    {
        res = "List is empty";
    }
    return res;
}

string DoublyLinkedList::deleteByValue(int value)
{

    string res = "Item isn't exist";
    if(this->isEmpty()) res = "List is empty";
    else
    {
        Node* tmp = this->m_pFirstNode;
        while (tmp)
        {
            Node* right = tmp->getRight();
            if(tmp->getData() == value)
            {
                if(tmp->getLeft() == nullptr)
                    res = this->deleteFirst();
                else if(tmp->getRight() == nullptr)
                    res = this->deleteLast();
                else
                {
                    Node* left = tmp->getLeft();
                    left->setRight(right);
                    right->setLeft(left);
                    delete tmp;
                    res = "Item is deleted";
                }
            }
            tmp = right;
        }
    }
    
    return res;
}

string DoublyLinkedList::displayForward()
{
    string res = "";
    if(this->isEmpty())
    {
        res = "List is empty";
    }
    else
    {
        Node* cur = this->m_pFirstNode;
        while (cur)
        {
            res += std::to_string(cur->getData()) + " ";
            cur = cur->getRight();
        }
    }
    return res;
}

string DoublyLinkedList::displayBackward()
{
    string res = "";
    if(this->isEmpty())
    {
        res = "List is empty";
    }
    else
    {
        Node* cur = this->m_pLastNode;
        while (cur)
        {
            res += std::to_string(cur->getData()) + " ";
            cur = cur->getLeft();
        }
    }
    return res;
}