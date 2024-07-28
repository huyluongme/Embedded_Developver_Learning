#include <iostream>

using namespace std;

#include "stack_or_queue.h"

template<typename T>
StackOrQueue<T>::StackOrQueue()
    : head(nullptr)
{
}

template<typename T>
StackOrQueue<T>::~StackOrQueue()
{
    while(!this->isEmpty())
    {
        pop();
    }
}

template<typename T>
bool StackOrQueue<T>::isEmpty()
{
    return this->head == nullptr;
}

template<typename T>
T StackOrQueue<T>::pop()
{
    if(!this->isEmpty())
    {
        Element* tmp = this->head;
        T infor = this->head->getInfor();
        this->head = this->head->getNext();
        delete tmp;
        return infor;
    }
    else throw std::underflow_error("Empty");
}

template class StackOrQueue<int>;
template class StackOrQueue<double>;