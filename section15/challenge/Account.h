//* section15 challenge
//* header file of Account.h - simple Account class

#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <iostream>
#include <string>

class Account {
    // friend Overloaded Extraction operator  
    friend std::ostream &operator<<(std::ostream &, const Account &);

    static constexpr const char *defName = "Unnamed Account";
    static constexpr double defBalance   = 0.0;

protected:
    //attribute
    std::string name;
    double balance;

public:
    Account(std::string name = defName, double balance = defBalance);               // default constructor
    bool deposit(double);                                                           // deposit()
    bool withdraw(double);
 //   std::string getName() const;                                                    // getter                                                          // withdraw()
    double getBalance() const;                                                      // getter

};

#endif
