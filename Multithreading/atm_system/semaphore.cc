#include "semaphore.h"

Semaphore::Semaphore(int count) : m_count(count) {}

Semaphore::~Semaphore() {}

void Semaphore::wait() {
    std::unique_lock<std::mutex> lock(m_sem_mutex);
    m_cv.wait(lock, [this]() {return m_count > 0;});
    --m_count;
}

void Semaphore::notify() {
    std::unique_lock<std::mutex> lock(m_sem_mutex);
    ++m_count;
    m_cv.notify_one();
}