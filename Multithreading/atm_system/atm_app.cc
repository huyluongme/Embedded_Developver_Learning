#include "atm_app.h"
#include "atm_exceptions.h"

ATMApp::ATMApp() {
    m_atm_services = new ATMService();
}

ATMApp::~ATMApp() {
    delete m_atm_services;
}

void ATMApp::checkATMBalanceFeature() {
    std::cout << "Balance of ATM: " << m_atm_services->checkATMBalanceService() << '\n';
}

void ATMApp::checkUserBalanceFeature(UserAccount* user) {
    std::cout << "Balance of " << user->getUserName() << ": " << user->getUserBalance() << '\n';
}

void ATMApp::withdrawFeature(UserAccount* user, int amount) {
    try
    {
        m_atm_services->withdrawService(user, amount);
        std::cout << user->getUserName() << ": Withdrawal of " << amount << " was successful. ";
        std::cout << "Balance of " << user->getUserName() << " is: " << user->getUserBalance() << "\n";
    }
    catch (const UserInsufficientFundsException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const ATMInsufficientFundsException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void ATMApp::depositFeature(UserAccount* user, int amount) {
    m_atm_services->depositService(user, amount);
    std::cout << user->getUserName() << ": Deposit of " << amount << " was successfull. ";
    std::cout << "Balance of " << user->getUserName() << " is: " << user->getUserBalance() << "\n";
}