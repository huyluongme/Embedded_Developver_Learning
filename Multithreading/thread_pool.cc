// Author: huyluongme
//
// This file is a simple example of thread pool in C++

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <functional>
#include <atomic>
#include <queue>

class ThreadPool
{
private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex queueMutex;
    std::condition_variable condition;
    std::atomic<bool> stop;
    void workerThread();

public:
    ThreadPool(size_t numThreads);
    ~ThreadPool();
    
    template<typename F>
    void enQueue(F&& task);
};

ThreadPool::ThreadPool(size_t numThreads) : stop(false)
{
    for(size_t i = 0; i < numThreads; i++)
        workers.emplace_back(&ThreadPool::workerThread, this);
}

ThreadPool::~ThreadPool()
{
    stop = true;
    condition.notify_all();
    for(std::thread &worker : workers)
        worker.join();
}

void ThreadPool::workerThread()
{
    while(true)
    {
        std::function<void()> task;
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            condition.wait(lock, [this]{ return stop || !tasks.empty();});
            if(stop && tasks.empty()) return;
            task = std::move(tasks.front());
            tasks.pop();
        }
        task();
    }
}

template<typename F>
void ThreadPool::enQueue(F&& task)
{
    {
        std::unique_lock<std::mutex> lock(queueMutex);
        tasks.emplace(std::forward<F>(task));
    }
    condition.notify_one();
}

std::mutex cout_lock;

void exampleTask(int id)
{
    {
        std::lock_guard<std::mutex> lock(cout_lock);
        std::cout << "Task " << id << " is being processed by thread " << std::this_thread::get_id() << "\n";
    }
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

void print_number(int num)
{
    {
        std::lock_guard<std::mutex> lock(cout_lock);
        std::cout << "Print number: " << num << "\n";
    }
}

int main()
{
    ThreadPool pool(5);
    // for(int i = 0; i < 10; i++)
    //     pool.enQueue([i] {print_number(i);});

    // std::this_thread::sleep_for(std::chrono::seconds(10));
    return 0;
}