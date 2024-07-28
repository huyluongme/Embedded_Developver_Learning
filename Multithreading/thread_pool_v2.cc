// Author: huyluongme
//
// This file is a simple example of thread pool in C++ - Version 2

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <functional>
#include <atomic>
#include <queue>
#include <windows.h>

class ThreadPool
{
private:
    std::mutex mu;
    std::vector<std::thread> threads;
    std::queue<std::function<void()>> jobs;
    void threadFunc(int thread_id);
    bool shouldTerminal = false;
    std::condition_variable cond;

public:
    void start(int thread_num);
    void enQueueJob(std::function<void()> &job);
    void stop();
    bool isBusy();
};

void ThreadPool::start(int thread_num)
{
    for(int i = 0; i < thread_num; i++)
        threads.push_back(std::thread(&ThreadPool::threadFunc, this, i));
}

void ThreadPool::threadFunc(int thread_id)
{   
    while(true)
    {
        std::function<void()> job;
        std::unique_lock<std::mutex> lock(mu);
        cond.wait(lock, [this]{return !jobs.empty() || shouldTerminal;});
        if(shouldTerminal) return;
        if(!jobs.empty())
        {
            job = jobs.front();
            jobs.pop();
        }
        job();
    }
}

void ThreadPool::enQueueJob(std::function<void()> &job)
{
    std::lock_guard<std::mutex> lock(mu);
    jobs.push(job);
    cond.notify_one();
}

bool ThreadPool::isBusy()
{
    std::lock_guard<std::mutex> lock(mu);
    return !jobs.empty();
}

void ThreadPool::stop()
{
    std::lock_guard<std::mutex> lock(mu);
    shouldTerminal = true;
    cond.notify_all();

    for(auto &t : threads)
        t.join();

    threads.clear();
}

void print_number(int num)
{
    std::cout << "Print number: " << num << "\n";
}

int main()
{
    ThreadPool pool;
    pool.start(5);
    Sleep(1);
    std::function<void()> job;
    for(int i = 1; i <= 10; i++)
    {
        job = std::bind(print_number, i);
        pool.enQueueJob(job);
    }
    return 0;
}