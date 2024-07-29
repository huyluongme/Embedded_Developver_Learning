#ifndef USER_ACCOUNT_H
#define USER_ACCOUNT_H

#include <iostream>
#include <string>

class UserAccount
{
private:
    std::string m_name;
    int m_user_balance;
    
public:
    UserAccount(std::string name, int user_balance);
    ~UserAccount();

    std::string getUserName();
    int         getUserBalance();
    void        withdrawUser(int amount);
    void        depositUser(int amount);
};

#endif