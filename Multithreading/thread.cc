// Author: huyluongmw
//
// This file is a simple example of multithreading in C++

#include <iostream>
#include <thread>


void functionA(char symbol)
{
    for(int i = 0; i < 200; i++)
        std::cout << symbol;
}

void functionB(int num)
{
    for(int i = 0; i < 200; i++)
        std::cout << num;
}

int main()
{
    std::cout << "Without multi-threading:\n";
    functionA('+');
    functionB(5);

    std::cout << "With multi-threading:\n";
    std::thread worker1(functionA, '+');
    std::thread worker2(functionB, 5);
    worker1.join();
    worker2.join();
    return 0;
}