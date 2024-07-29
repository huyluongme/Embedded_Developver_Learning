#include "atm_service.h"
#include "atm_exceptions.h"

ATMService::ATMService() {
    m_atm = new ATM(100000);
}

ATMService::~ATMService() {
    delete m_atm;
}

int ATMService::checkATMBalanceService() {
    return m_atm->getATMBalance();
}

int ATMService::checkUserBalanceService(UserAccount* user) {
    return user->getUserBalance();
}

void ATMService::withdrawService(UserAccount* user, int amount) {
    if(amount > user->getUserBalance()) {
        throw UserInsufficientFundsException();
    }
    
    if(amount > m_atm->getATMBalance()) {
        throw ATMInsufficientFundsException();
    }

    m_atm->withdrawFromATM(amount);
    user->withdrawUser(amount);

    // if(amount <= user->getUserBalance() && amount <= m_atm->getATMBalance()) {
    //     m_atm->withdrawFromATM(amount);
    //     user->withdrawUser(amount);
    // }
}

void ATMService::depositService(UserAccount* user, int amount) {
    m_atm->depositToATM(amount);
    user->depositUser(amount);
}