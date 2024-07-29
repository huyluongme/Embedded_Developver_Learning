#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

#include "user_account.h"
#include "atm_app.h"

ATMApp* atm_app = new ATMApp();

void test_transaction(UserAccount* user,int withdraw_amount, int deposit_amount)
{
    atm_app->withdrawFeature(user, withdraw_amount);
    atm_app->depositFeature(user, deposit_amount);
}

int main()
{
    std::vector<std::thread> threads;
    UserAccount* user1 = new UserAccount("Huy", 8000);
    UserAccount* user2 = new UserAccount("Thao", 8000);
    for(int i = 0 ; i < 5; i++)
    {
        threads.emplace_back(test_transaction, user1, 50, 100);
    }

    for(auto& t : threads)
        t.join();

    std::cout << "\n\n";
    atm_app->checkATMBalanceFeature();
    // UserAccount* user1 = new UserAccount("Huy", 500);
    // UserAccount* user2 = new UserAccount("Thao", 700);

    // // atm_app->checkATMBalanceFeature();
    // // std::cout << "ATM Balance: " << atm_balance << '\n';

    // std::thread t1(test, user1, 200);
    // std::thread t2(test, user2, 300);
    // t1.join();
    // t2.join();

    // // std::cout << "ATM Balance: " << atm_balance << '\n';
    // // atm_app->checkATMBalanceFeature();

    delete atm_app;
    return 0;
}