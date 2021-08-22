//* section15 challenge
//* checkingAccount implementation file. 

//  Checking account class to the Account hierarchy

#include "Account.h"
#include "CheckingAccount.h"
#include "ExceptionClass.h"

// default constructor
CheckingAccount::CheckingAccount(std::string name, double balance) 
    : Account{name, balance} {
        if (balance < 0) {
            throw IllegalBalanceException();
        }
    }


//  overriden withdraw function 
//  A Checking account has a name and a balance and has a fee of $1.50 per withdrawal transaction.
//  Every withdrawal transaction will be assessed this flat fee.
bool CheckingAccount::withdraw(double amount) {
    amount += defTransactionFee;
    return Account::withdraw(amount);
}


// overriden CheckingAccount::deposit()
// deposit method is inherited from Account class and have same implementation
bool CheckingAccount::deposit(double amount) {
    return Account::deposit(amount);
}

// print()
void CheckingAccount::print(std::ostream &os) const{
    os << "[Checking_Account: " << name << ": " << balance  << "]";
}

