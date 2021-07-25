//* section15 challenge
//* AccountUtil header file - helper funtions for Account class and SavingAccount class

#ifndef _ACCOUNTUTIL_H_
#define _ACCOUNTUTIL_H_

#include <vector>
#include "Account.h"
#include "SavingAccount.h"
#include "CheckingAccount.h"
#include "TrustAccount.h"

// Utility helper functions for Account class
void display(const std::vector<Account> &);
void deposit(std::vector<Account> &, double);
void withdraw(std::vector<Account> &, double);

// Utility helper functions for SavingAccount class
void display(const std::vector<SavingAccount> &);
void deposit(std::vector<SavingAccount> &, double);
void withdraw(std::vector<SavingAccount> &, double);

// Utility helper functions for CheckingAccount class
void display(const std::vector<CheckingAccount> &);
void deposit(std::vector<CheckingAccount> &, double);
void withdraw(std::vector<CheckingAccount> &, double);

// Utility helper functions for TrustAccount class
void display(const std::vector<TrustAccount> &);
void deposit(std::vector<TrustAccount> &, double);
void withdraw(std::vector<TrustAccount> &, double);

#endif
