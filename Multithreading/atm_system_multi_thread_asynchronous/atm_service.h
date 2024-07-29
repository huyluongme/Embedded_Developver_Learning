#ifndef ATM_SERVICE_H
#define ATM_SERVICE_H

#include "atm.h"
#include "user_account.h"

class ATMService
{
private:
    ATM* m_atm;
public:
    ATMService();
    ~ATMService();

    int checkATMBalanceService();
    int checkUserBalanceService(UserAccount* user);
    void withdrawService(UserAccount* user, int amount);
    void depositService(UserAccount* user, int amount);
};

#endif