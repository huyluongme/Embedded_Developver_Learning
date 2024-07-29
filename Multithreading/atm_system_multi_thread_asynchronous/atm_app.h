#ifndef ATM_APP_H
#define ATM_APP_H

#include "atm_service.h"

class ATMApp
{
private:
    ATMService* m_atm_services;
public:
    ATMApp();
    ~ATMApp();

    void checkATMBalanceFeature();
    void checkUserBalanceFeature(UserAccount* user);
    void withdrawFeature(UserAccount* user, int amount);
    void depositFeature(UserAccount* user, int amount);
};

#endif