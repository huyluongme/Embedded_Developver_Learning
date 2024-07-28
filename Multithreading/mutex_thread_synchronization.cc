// Author: huyluongme
// 
// This file is a simple example of use mutex to thread synchronization in C++

#include <iostream>
#include <thread>
#include <mutex>

int task1 = 0, taks2 = 0;
std::mutex job_lock;

void doTaskWithoutMutex()
{
    task1 += 1;
    std::cout << "Task " << task1 << " is started\n";
    std::this_thread::sleep_for(std::chrono::seconds(2)); // sleep 2 seconds
    std::cout << "Task " << task1 << " is finished\n";
}

void doTaskWithMutex()
{
    std::lock_guard<std::mutex> do_job_lock(job_lock);
    taks2 += 1;
    std::cout << "Task " << taks2 << " is started\n";
    for(long i; i < 10e8; i++);
    std::cout << "Task " << taks2 << " is finished\n";
}

int main()
{
    std::cout << "Thread not synchronized:\n";
    std::thread t1(doTaskWithoutMutex);
    std::thread t2(doTaskWithoutMutex);
    t1.join();
    t2.join();

    std::cout << "\nThread is synchronized:\n";
    std::thread t3(doTaskWithMutex);
    std::thread t4(doTaskWithMutex);
    t3.join();
    t4.join();
    return 0;
}