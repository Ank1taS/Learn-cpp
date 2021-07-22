//Todo          header file of derived class savingsAccount.h
//Todo          savingsAccount.h

#ifndef _SAVINGSACCOUNT_H_
#define _SAVINGSACCOUNT_H_

#include "account.h"

class SavingsAccount: public Account {

    friend std::ostream &operator<<(std::ostream &, const SavingsAccount &);    // friend extraction operator overloaded function 

protected:
    // attribute
    double interestRate;

public:
    SavingsAccount();                       // default constructor
    SavingsAccount(double, double);         // overloaded constructor
    void deposit(double);                   // deposit method
    // withdraw method is inherited from Account class
};

#endif
