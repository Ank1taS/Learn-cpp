//* section15 challenge
//* implementation file of Account.h 
//* Account.cpp - simple Account class

#include "Account.h"

//default constructor 
Account::Account(std::string name, double balance)
    : name {name}, balance {balance} {}

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

// getter getBalance function
double Account::getBalance() const {
    return balance;
}

// // getter getName function
// std::string Account::getName() const {
//     return name;
// }

// extraction operator overloading
std::ostream &operator<<(std::ostream &os, const Account &obj) {
    os << "[Account: " << obj.name << ": " << obj.balance << "]";
    return os;
}
