//* Section15 Challenge
//* main.cpp - 

#include <iostream>
#include <vector>
#include "Account.h"
#include "SavingAccount.h"
#include "CheckingAccount.h"
#include "TrustAccount.h"
#include "AccountUtil.h"

using namespace std; 

int main() {
    cout.precision(2);
    cout << fixed;
   
    // Accounts
    vector<Account> accounts;
    accounts.push_back(Account {});
    accounts.push_back(Account {"Larry"});
    accounts.push_back(Account {"Moe", 2000} );
    accounts.push_back(Account {"Curly", 5000} );
    
    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts,2000);
    
    // Savings 

    vector<SavingAccount> sav_accounts;
    sav_accounts.push_back(SavingAccount {} );
    sav_accounts.push_back(SavingAccount {"Superman"} );
    sav_accounts.push_back(SavingAccount {"Batman", 2000} );
    sav_accounts.push_back(SavingAccount {"Wonderwoman", 5000, 5.0} );

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts,2000);
   
   // Checking
   
    vector<CheckingAccount> check_accounts;
    check_accounts.push_back(CheckingAccount {} );
    check_accounts.push_back(CheckingAccount {"Kirk"} );
    check_accounts.push_back(CheckingAccount {"Spock", 2000} );
    check_accounts.push_back(CheckingAccount {"Bones", 5000} );

    display(check_accounts);
    deposit(check_accounts, 1000);
    withdraw(check_accounts, 2000);

    // Trust
  
    vector<TrustAccount> trust_accounts;
    trust_accounts.push_back(TrustAccount {} );
    trust_accounts.push_back(TrustAccount {"Athos", 10000, 5.0} );
    trust_accounts.push_back(TrustAccount {"Porthos", 20000, 4.0} );
    trust_accounts.push_back(TrustAccount {"Aramis", 30000} );

    display(trust_accounts);
    deposit(trust_accounts, 1000);
    withdraw(trust_accounts, 3000);
    
    // Withdraw 5 times from each trust account
    // All withdrawals should fail if there are too many withdrawals or if the withdrawl is > 20% of the balance
    for (int i=1; i<=5; i++)
        withdraw(trust_accounts, 1000);
       
    return 0;
}

