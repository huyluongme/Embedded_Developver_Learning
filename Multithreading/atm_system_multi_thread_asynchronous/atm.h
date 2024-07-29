#ifndef ATM_H
#define ATM_H

class ATM
{
private:
    int m_atm_balance;
    
public:
    ATM(int atm_balance);
    ~ATM();

    int getATMBalance();
    void withdrawFromATM(int amount);
    void depositToATM(int amount);
};

#endif