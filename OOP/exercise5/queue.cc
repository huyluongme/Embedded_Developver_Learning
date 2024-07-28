#include "queue.h"

template<typename T>
Queue<T>::Queue() : StackOrQueue<T>(), m_tail(nullptr)
{
}

template<typename T>
Queue<T>::~Queue()
{
}

template<typename T>
void Queue<T>::insert(T infor)
{
    typename StackOrQueue<T>::Element* newEle = new typename StackOrQueue<T>::Element(infor);
    if(this->isEmpty())
    {
        this->head = newEle;
        this->m_tail = newEle;
    }
    else
    {
        this->m_tail->setNext(newEle);    
        this->m_tail = newEle;
    }
}

template class Queue <int>;
template class Queue <double>;