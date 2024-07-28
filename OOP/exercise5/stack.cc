#include "stack.h"

template<typename T>
Stack<T>::Stack() : StackOrQueue<T>()
{
}

template <typename T>
Stack<T>::~Stack()
{
}

template<typename T>
void Stack<T>::push(T infor)
{
    typename StackOrQueue<T>::Element* newEle = new typename StackOrQueue<T>::Element(infor);
    newEle->setNext(this->head);
    this->head = newEle;
}


template class Stack<int>;
template class Stack<double>;