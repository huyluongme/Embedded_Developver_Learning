#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <mutex>
#include <condition_variable>

class Semaphore
{
private:
    std::mutex m_sem_mutex;
    std::condition_variable m_cv;
    int m_count;
public:
    Semaphore(int count = 0);
    ~Semaphore();

    void wait();
    void notify();
};

#endif