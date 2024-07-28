#ifndef STACK_OR_QUEUE_H
#define STACK_OR_QUEUE_H

template<typename T>
class StackOrQueue
{
protected:
    class Element
    {
    private:
        T m_infor;
        Element* m_next;
    public:
        Element(T infor) :m_infor(infor), m_next(nullptr) {}
        ~Element() {}
        T getInfor() { return this->m_infor; }
        Element* getNext() {return this->m_next; };
        void setNext(Element* newEle) {this->m_next = newEle; }
    };
    Element* head;
public:
    StackOrQueue();
    ~StackOrQueue();

    bool isEmpty();
    T pop();
};

#endif