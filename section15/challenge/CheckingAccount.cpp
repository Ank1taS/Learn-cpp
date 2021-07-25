//* section15 challenge
//* checkingAccount implementation file - 

//  Checking account class to the Account hierarchy

#include "Account.h"
#include "CheckingAccount.h"

// default constructor
CheckingAccount::CheckingAccount(std::string name, double balance) 
    : Account{name, balance} {}

//  overloaded withdraw function 
//  A Checking account has a name and a balance and has a fee of $1.50 per withdrawal transaction.
//  Every withdrawal transaction will be assessed this flat fee.
bool CheckingAccount::withdraw(double amount) {
    amount += defTransactionFee;
    return Account::withdraw(amount);
}

// overloaded extraction operator
std::ostream &operator<<(std::ostream &os, const CheckingAccount &obj) {
    os << "[Checking_Account: " << obj.name << ": " << obj.balance  << "]";
    return os;
}