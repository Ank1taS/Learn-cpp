//* section15 challenge
//* header file of SavingAccount - a type of Account

#ifndef _SAVINGACCOUNT_H_
#define _SAVINGACCOUNT_H_

#include "Account.h"

class SavingAccount: public Account{
    // friend Overloaded Extraction operator  
    friend std::ostream &operator<<(std::ostream &, const SavingAccount &);             

    static constexpr const char *defName = "Unname SavingAccount";
    static constexpr double defBalance = 0.0;
    static constexpr double defInterestRate = 0.0;

protected:
    // attribute
    double interestRate;        // interest rate

public:
    SavingAccount(std::string name = defName, double balance = defBalance, double interestRate = defInterestRate);  // default constructor 

    // Deposit:
    // Amount supplied to deposit will be incremented by (amount * int_rate/100) and then the updated amount will be deposited
    bool deposit(double);

    // Inherits the Account::withdraw() - same as a regular account

};

#endif
