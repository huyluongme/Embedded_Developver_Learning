// Author: huyluongme
// 
// This file is a simple example of use semaphore to thread synchronization in C++

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

class Semaphore
{
private:
    std::mutex mtx;
    std::condition_variable cv;
    int count;
public:
    Semaphore(int count = 0) : count(count) {};
    ~Semaphore() {};

    void wait()
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]() { return count > 0;});
        --count;
    }

    void notify()
    {
        std::unique_lock<std::mutex> lock(mtx);
        ++count;
        cv.notify_one();
    }
};

Semaphore sem(3);
std::mutex cout_lock;

void worker(int id)
{
    {
        std::lock_guard<std::mutex> lock(cout_lock);
        std::cout << "Worker " << id << " is waiting to access the resource\n";
    }
    sem.wait();
    {
        std::lock_guard<std::mutex> lock(cout_lock);
        std::cout << "Worker " << id << " is accessing the resource\n";
    }
    std::this_thread::sleep_for(std::chrono::seconds(2));
    {
        std::lock_guard<std::mutex> lock(cout_lock);
        std::cout << "Worker " << id << " id done and releasing the resource\n";
    }
    sem.notify();
}

int main()
{   
    std::vector<std::thread> threads;
    
    for(int i = 1; i <= 5; i++)
        threads.push_back(std::thread(worker, i));

    for(auto& t : threads)
        t.join();
        
    return 0;
}