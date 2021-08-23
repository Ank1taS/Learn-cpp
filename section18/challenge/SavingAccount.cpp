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

// overriding withdraw()
// SavingAccount::withdraw() is inherited from Account class and have same implementation
bool SavingAccount::withdraw(double amount) {
    return Account::withdraw(amount);
}

// print()
void SavingAccount::print(std::ostream &os) const {
    os << "[Savings_Account: " << name << ": " << balance << ", " << interestRate << "%]";
}
