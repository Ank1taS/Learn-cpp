#include <iostream>
#include <memory>
#include "Account.h"
#include "CheckingAccount.h"
#include "SavingAccount.h"
#include "TrustAccount.h"
#include "AccountUtil.h"
#include "InsufficentFundsException.h"
#include "IllegalBalanceException.h"

using namespace std;

int main() {
    try {
        std::unique_ptr<Account> ptrSavingAcc = std::make_unique<SavingAccount> ("Jhon", 5000);
        std::cout << *ptrSavingAcc << std::endl;

        std::unique_ptr<Account> ptrAcc1 = std::make_unique<CheckingAccount> ("Frank", -1000);
        std::cout << *ptrAcc1 << std::endl;
    }
    catch (IllegalBalanceException &ex) {
        std::cerr << ex.what() << std::endl;
    }

    try {

        std::unique_ptr<Account> ptrCheckingAcc1 = std::make_unique<CheckingAccount> ("Ammy", 2000);
        std::cout << *ptrCheckingAcc1 << std::endl;

        std::unique_ptr<Account> ptrSavingAcc = std::make_unique<SavingAccount> ("Jhon", 5000);
        std::cout << *ptrSavingAcc << std::endl;

        std::unique_ptr<Account> ptrTrustAcc = std::make_unique<TrustAccount> ("Zaden", 2500);
        std::cout << *ptrTrustAcc << std::endl;

        ptrSavingAcc->withdraw(2000);
        std::cout << *ptrSavingAcc << std::endl;

        ptrTrustAcc->withdraw(3000);
        std::cout << *ptrTrustAcc << std::endl;

    }
    catch (IllegalBalanceException &ex) {
        std::cerr << ex.what() << std::endl;
    }
    catch (InsufficentFundException &ex) {
        std::cerr << ex.what() << std::endl;
    }
    
    std::cout << "Program completed...." << std::endl;

    return 0;
}

