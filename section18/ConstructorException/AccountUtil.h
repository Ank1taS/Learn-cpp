//* section15 challenge
//* AccountUtil header file - helper funtions for Account class and SavingAccount class

#ifndef _ACCOUNTUTIL_H_
#define _ACCOUNTUTIL_H_

#include <vector>
#include "Account.h"
#include "SavingAccount.h"
#include "CheckingAccount.h"
#include "TrustAccount.h"

// Utility helper functions for Derived classes of Account class,  
void display(const std::vector<Account *> &);
void deposit(std::vector<Account *> &, double);
void withdraw(std::vector<Account *> &, double);

#endif
