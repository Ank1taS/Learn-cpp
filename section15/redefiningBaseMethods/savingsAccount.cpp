//Todo          Implimentation of derived class savingsAccount
//Todo          savingsAccount.cpp

#include "savingsAccount.h"


// default constructor - delegating constructor
SavingsAccount::SavingsAccount()
    : SavingsAccount(0.0, 0.0) {
    std::cout << "Savings account default constructor" << std::endl;
}

// overloaded parameterised constructor
SavingsAccount::SavingsAccount(double amount, double interest)
    : Account(amount), interestRate {interest} {
    std::cout << "Saving account overloaded(double, double) constructor" << std::endl;
}

// Deposit method increments amount to be deposited by amount * int_rate percentage!!
void SavingsAccount::deposit(double amount) {
    amount += amount * interestRate / 100;
    Account::deposit(amount); 
}

// Withdraw method does not specialize

// overloaded extraction operator
std::ostream &operator<<(std::ostream &os, const SavingsAccount &sourceObj) {
    os << "Saving account balance - " << sourceObj.balance << "  with interest - " << sourceObj.interestRate << "%" << std::endl;

    return os; 
}
