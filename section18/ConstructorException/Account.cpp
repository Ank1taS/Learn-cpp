//* section15 challenge
//* implementation file of Account.h 
//* Account.cpp - simple Account class

#include "Account.h"
#include "ExceptionClass.h"

//default constructor 
Account::Account(std::string name, double balance)
    : name {name}, balance {balance} {
        if (balance < 0) {
            throw IllegalBalanceException();
        }
    }

// deposit function
bool Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        return true;
    }
    else
        return false;
}

// withdraw function
bool Account::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}
