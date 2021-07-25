//* section15 challenge
//* implementation of SavingAccount - a type of Account

#include "SavingAccount.h"

// default constructor
SavingAccount::SavingAccount(std::string name, double balance, double interestRate) 
    : Account{name, balance}, interestRate {interestRate} {

}

// Deposit:
// Amount supplied to deposit will be incremented by (amount * int_rate/100) and then the updated amount will be deposited
bool SavingAccount::deposit(double amount) {
    amount += amount * interestRate / 100;
    return Account::deposit(amount);
}

// << operator overloading
std::ostream &operator<<(std::ostream &os, const SavingAccount &obj) {
    os << "[Savings_Account: " << obj.name << ": " << obj.balance << ", " << obj.interestRate << "%]";
    return os;
}
