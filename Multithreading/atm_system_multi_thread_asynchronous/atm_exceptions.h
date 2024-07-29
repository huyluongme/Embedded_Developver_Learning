#ifndef ATM_EXCEPTIONS_H
#define ATM_EXCEPTIONS_H

#include <exception>
#include <string>

class ATMInsufficientFundsException : public std::exception {
public:
    const char* what() const noexcept override {
        return "ATM does not have enough funds for this transaction.";
    }
};

class UserInsufficientFundsException : public std::exception {
public:
    const char* what() const noexcept override {
        return "User account does not have enough funds for this transaction.";
    }
};


#endif