#ifndef QUEUE_H
#define QUEUE_H

#include "stack_or_queue.h"

template<typename T>
class Queue : public StackOrQueue<T>
{
private:    
    typename StackOrQueue<T>::Element* m_tail;
public:
    Queue();
    ~Queue();

    void insert(T infor);
};

#endif