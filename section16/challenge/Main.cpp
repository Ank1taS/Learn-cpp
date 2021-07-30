#include <iostream>
#include <memory>
#include "Account.h"
#include "CheckingAccount.h"
#include "SavingAccount.h"
#include "TrustAccount.h"
#include "AccountUtil.h"

using namespace std;

int main() {
//    
    // Account frank{"Frank", 5000};         // should not compile
    // cout << frank << endl;

    CheckingAccount frank {"Frank", 5000};
    cout << frank << endl;
    
    Account *trust = new TrustAccount("James");
    cout << *trust << endl;
    
    Account *p1 = new CheckingAccount("Larry", 10000);
    Account *p2 = new SavingAccount("Moe", 1000);
    Account *p3 = new TrustAccount("Curly");
    
    std::vector<Account *> accounts {p1,p2,p3};
    
    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);
    
    display(accounts);
    
    delete p1;
    delete p2;
    delete p3;
    
    return 0;
}

