//* section15 challenge
//* checkingAccount header file - 

//  Checking account class to the Account hierarchy
//  A Checking account has a name and a balance and has a fee of $1.50 per withdrawal transaction.
//  Every withdrawal transaction will be assessed this flat fee.

#ifndef _CHECKINGACCOUNT_H_
#define _CHECKINGACCOUNT_H_

#include "Account.h"

class CheckingAccount: public Account {

    static constexpr const char *defName      = "Unname Checking Account";
    static constexpr double defBalance        = 0.0;
    static constexpr double defTransactionFee = 1.50;       // const attribute    

public:
    CheckingAccount(std::string name = defName, double balance = defBalance);       // default constructor
    virtual void print(std::ostream &)const override;                               // overriden virtual print()
    virtual bool withdraw(double) override;                                         // overriden virtual withdraw() 
    virtual bool deposit(double) override;                                          // overriden virtual deposit() 
    virtual ~CheckingAccount() = default;                                           // virtual destructor

};

#endif
