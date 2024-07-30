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

void DoublyLinkedList::insertFirst(int value)
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
}

void DoublyLinkedList::insertLast(int value)
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
}

void DoublyLinkedList::insertAfterValue(int newValue, int targetValue)
{
    Node* searchNode = this->search(targetValue);
    if(searchNode)
    {
        Node* newNode = new Node(newValue, nullptr, nullptr);
        if(searchNode->getRight() == nullptr){
            this->insertLast(newValue);
        }
        else
        {
            Node* nextNodeOfSeachNode = searchNode->getRight();
            searchNode->setRight(newNode);
            nextNodeOfSeachNode->setLeft(newNode);
            newNode->setLeft(searchNode);
            newNode->setRight(nextNodeOfSeachNode);
            this->m_numOfElements += 1;
        }
    }
    else
    {
        throw TargetValueIsNotExist();
    }
}

void DoublyLinkedList::insertAfterID(int newValue, int id)
{
    if(id < 1 || id > this->m_numOfElements) throw IDInvalid();
    Node* tmp = this->m_pFirstNode;
    int cnt = 0;
    while(cnt < id - 1)
    {
        tmp = tmp->getRight();
        cnt += 1;
    }
    if(tmp->getRight() == nullptr){
        this->insertLast(newValue);
    }
    else
    {
        Node* newNode = new Node(newValue, nullptr, nullptr);
        Node* nextNodeOfCurNode = tmp->getRight();
        tmp->setRight(newNode);
        nextNodeOfCurNode->setLeft(newNode);
        newNode->setLeft(tmp);
        newNode->setRight(nextNodeOfCurNode);
        this->m_numOfElements += 1;
    }
}

void DoublyLinkedList::deleteFirst()
{
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
    }
    else
    {
        throw ListIsEmpty();
    }
}

void DoublyLinkedList::deleteLast()
{
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
    }
    else
    {
        throw ListIsEmpty();
    }
}

void DoublyLinkedList::deleteByValue(int value)
{

    if(this->isEmpty()) throw ListIsEmpty();
    else
    {
        Node* tmp = this->m_pFirstNode;
        bool isFound = false;
        while (tmp)
        {
            Node* right = tmp->getRight();
            if(tmp->getData() == value)
            {
                if(tmp->getLeft() == nullptr)
                    this->deleteFirst();
                else if(tmp->getRight() == nullptr)
                    this->deleteLast();
                else
                {
                    Node* left = tmp->getLeft();
                    left->setRight(right);
                    right->setLeft(left);
                    delete tmp;
                }
                isFound = true;
            }
            tmp = right;
        }
        if(!isFound) throw ItemNotExist();
    }
}

void DoublyLinkedList::deleteByID(int id)
{
    if(id < 1 || id > this->m_numOfElements) throw IDInvalid();
    if(this->isEmpty()) throw ListIsEmpty();
    else
    {
        Node* tmp = this->m_pFirstNode;
        int cnt = 0;
        while(cnt < id - 1) 
        {
            tmp = tmp->getRight();
            cnt += 1;
        }
        if(tmp->getLeft() == nullptr)
            this->deleteFirst();
        else if(tmp->getRight() == nullptr)
            this->deleteLast();
        else
        {
            Node* left = tmp->getLeft();
            Node* right = tmp->getRight();
            left->setRight(right);
            right->setLeft(left);
            delete tmp;
        }
    }
}

string DoublyLinkedList::displayForward()
{
    string res = "";
    if(this->isEmpty())
    {
        throw ListIsEmpty();
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
        throw ListIsEmpty();
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