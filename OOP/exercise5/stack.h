#ifndef STACK_H
#define STACK_H

#include "stack_or_queue.h"

template<typename T>
class Stack : public StackOrQueue<T>
{
public:
    Stack();
    ~Stack();
    void push(T infor);
};

#endif