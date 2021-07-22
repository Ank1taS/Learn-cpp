//Todo          implimentation oh base class Account
//Todo          account.cpp

#include "account.h"

// overloaded single parameterised constructor
Account::Account(double amount)
    : balance {amount} {
    std::cout << "Account class overloaded(double) constructor." << std::endl;
}

// default constructor - delegating constructor
Account::Account()
    : Account(0.0) {
    std::cout << "Account class default constructor." << std::endl;
}

// deposit method 
void Account::deposit(double amount) {
    balance += amount;
}

// withdraw method
void Account::withdraw(double amount) {
    if (balance < amount) {
        std::cout << "Insufficient funds" << std::endl;
    }
    else {
        balance -= amount;
    }
}

// overloaded extraction operator
std::ostream &operator<<(std::ostream &os, const Account &sourceObj) {
    os <<  "Account balance: " << sourceObj.balance << std::endl;

    return os;
}


