//* section15 challenge
//* header file of SavingAccount - a type of Account
    
// Amount supplied to deposit will be incremented by (amount * int_rate/100) and then the updated amount will be deposited

#ifndef _SAVINGACCOUNT_H_
#define _SAVINGACCOUNT_H_

#include "Account.h"

class SavingAccount: public Account{

    static constexpr const char *defName = "Unname SavingAccount";
    static constexpr double defBalance = 0.0;
    static constexpr double defInterestRate = 0.0;

protected:
    // attribute
    double interestRate;        // interest rate

public:
    SavingAccount(std::string name = defName, double balance = defBalance, double interestRate = defInterestRate);  // default constructor 

    virtual void print(std::ostream &) const override;          // overriden virtual print()
    virtual bool deposit(double) override;                      // overriden virtual deposit()
    virtual bool withdraw(double) override;                     // overriden virtual withdraw() - same as a regular account
    virtual ~SavingAccount() = default;                         // virtual destructor()
};

#endif
