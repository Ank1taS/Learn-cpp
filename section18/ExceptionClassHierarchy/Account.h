//* section16 challenge
//* header file of Account.h - simple Account class

#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <iostream>
#include <string>
#include "IPrintable.h"

// abstract class Account
class Account: public IPrintable{

    static constexpr const char *defName = "Unnamed Account";
    static constexpr double defBalance   = 0.0;

protected:
    //attribute
    std::string name;
    double balance;

public:
    Account(std::string name = defName, double balance = defBalance);               // default constructor
    virtual void print(std::ostream &) const override = 0;                          // overriden pure virtual print() 
    virtual bool deposit(double)  = 0;                                              // pure virtual deposit()
    virtual bool withdraw(double) = 0;                                              // pure virtual withdraw()
    virtual ~Account() = default;                                                   // virtual destructor
};

#endif
