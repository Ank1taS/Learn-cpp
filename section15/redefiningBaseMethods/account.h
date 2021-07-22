//Todo          header file of base class Account
//Todo          header.h

#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <iostream>

class Account {
    friend std::ostream &operator<<(std::ostream &, const Account &);     // friend overloaded extraction operator

protected:
    // attribute
    double balance;


public:
    Account();                      // default constructor
    Account(double);                // overloaded constructor
    void deposit(double);           // method to deposit
    void withdraw(double);          // method to withdraw
};

#endif
