#include "atm.h"
#include <thread>

ATM::ATM(int atm_balance) : m_atm_balance(atm_balance) {}

ATM::~ATM() {}

int ATM::getATMBalance() {
    return m_atm_balance;
}

void ATM::withdrawFromATM(int amount) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    m_atm_balance -= amount;
}

void ATM::depositToATM(int amount) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    m_atm_balance += amount;
}