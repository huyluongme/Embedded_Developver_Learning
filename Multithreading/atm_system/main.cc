#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <atomic>

#include "user_account.h"
#include "atm_app.h"
#include "semaphore.h"

ATMApp* atm_app = new ATMApp();

std::mutex mtx;

Semaphore sem(3);
std::mutex cout_lock;

void test_transaction(UserAccount* user, int withdraw_amount, int deposit_amout)
{
    sem.wait();
    // std::lock_guard<std::mutex> lock(mtx);
    {
        std::lock_guard<std::mutex> lock(cout_lock);
        std::cout << user->getUserName() << " is using ATM.\n";
    }
    atm_app->withdrawFeature(user, withdraw_amount);
    atm_app->depositFeature(user, deposit_amout);
    {
        std::lock_guard<std::mutex> lock(cout_lock);
        std::cout << user->getUserName() << " is done using ATM.\n";
    }
    sem.notify();
}

std::vector<UserAccount*> users;

void initUsers(int user_num) {
    for(int i = 1; i <= user_num; i++)
        users.emplace_back(new UserAccount("[User " + std::to_string(i) +"]", (rand() % (5000 - 50 + 1))));

    std::cout << "List of user:\n";
    for(auto* user : users)
        std::cout << user->getUserName() << " with balance: " << user->getUserBalance() << '\n';
    std::cout << '\n';
}

enum ATMFeature {
    CHECK_BALANCE,
    WITHDRAW,
    DIPOSIT,
};

std::mutex rand_feature_lock;
std::atomic_int rand_feature;

void atmUse(ATMFeature feature, UserAccount* user){
    if(feature == ATMFeature::CHECK_BALANCE)
        atm_app->checkUserBalanceFeature(user);
    else if(feature == ATMFeature::WITHDRAW) {
        int withdraw_amount = rand() % (5000 - 50 + 1);
        atm_app->withdrawFeature(user, withdraw_amount);
    }
    else {
        int deposit_amount = rand() % (5000 - 50 + 1);
        atm_app->depositFeature(user, deposit_amount);
    }
}

ATMFeature feature;

void atmSimulator(UserAccount* user) {
    {
        std::lock_guard<std::mutex> lock(cout_lock);
        std::cout << user->getUserName() << " is waiting to use ATM.\n";
    }
    sem.wait();
    {
        std::lock_guard<std::mutex> lock(cout_lock);
        std::cout << user->getUserName() << " is using ATM.\n";
    }
    feature = ATMFeature(rand() % 3);
    std::this_thread::sleep_for(std::chrono::seconds(1));

    {
        std::lock_guard<std::mutex> lock(rand_feature_lock);
        feature = (ATMFeature)(rand() % (2 - 0 + 1));
        std::cout << feature << '\n';
        atmUse((ATMFeature)feature, user);
    }
    {
        std::lock_guard<std::mutex> lock(cout_lock);
        std::cout << user->getUserName() << " is done using ATM.\n";
    }
    sem.notify();
}

int main()
{
    srand(time(0));
    initUsers(10);
    std::vector<std::thread> threads;
    for(int i = 0; i < 5; i++)
        threads.push_back(std::thread(atmSimulator, users[i]));

    for(auto& t : threads)
        t.join();
    
    // for(int i = 0; i < 5; i++)
    //     std::cout << (ATMFeature)(rand() % 3) << "\n";
        
    // for (int i = 0; i < 5; i++) 
    //     std::cout << rand() << " "; 
    // std::vector<std::thread> threads;
    
    // for(int i = 1; i <= 5; i++)
    //     threads.push_back(std::thread(worker, i));

    // for(auto& t : threads)
    //     t.join();
    // std::vector<UserAccount*> users;

    // for(int i = 0; i < 10; i++)
    //     users.emplace_back(new UserAccount("user" + std::to_string(i + 1), 800));
    // std::vector<std::thread> threads;

    // for(int i = 0; i < 10; i++)
    // {
    //     threads.emplace_back(test_transaction, users.at(i), 50, 100);
    // }

    // for(auto& t : threads)
    // {
    //     t.join();
    // }

    // std::cout << "\n\n";

    // atm_app->checkATMBalanceFeature();

    delete atm_app;
    return 0;
}