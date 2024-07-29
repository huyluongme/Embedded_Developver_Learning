#ifndef ATM_H
#define ATM_H

#include <mutex>

class ATM
{
private:
    int m_atm_balance;
    std::mutex atm_balance_lock;
    
public:
    ATM(int atm_balance);
    ~ATM();

    int getATMBalance();
    void withdrawFromATM(int amount);
    void depositToATM(int amount);
};

#endif