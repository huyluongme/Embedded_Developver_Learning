#include "user_account.h"

UserAccount::UserAccount(std::string name, int user_balance)
    : m_name(name), m_user_balance(user_balance) {}

UserAccount::~UserAccount() {}

std::string UserAccount::getUserName() {
    return m_name;
}

int UserAccount::getUserBalance() {
    return m_user_balance;
}

void UserAccount::withdrawUser(int amount) {
    m_user_balance -= amount;
}

void UserAccount::depositUser(int amount) {
    m_user_balance += amount;
}