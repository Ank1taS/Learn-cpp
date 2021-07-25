//* section15 challenge
//* AccountUtil implementation file - helper funtions for Account class and SavingAccount class

#include "AccountUtil.h"

//============================================
// Utility helper functions for Account class
//============================================

// displays Account objects of a vector of account objects
void display(const std::vector<Account> &accVec) {
    std::cout << "\n=============== Accounts Details ===============" << std::endl;
 
    for (const auto &accObj: accVec) {
        std::cout << accObj << std::endl;
    }
}

// deposit new amount to each Account object of Account Vector
void deposit(std::vector<Account> &accVec, double amount) {
    std::cout << "\n=============== Depositing to Accounts ================" << std::endl;

    for (auto &accObj: accVec) {
        if(accObj.deposit(amount)) 
            std::cout << "Deposited " << amount << " to " << accObj << std::endl;
        else 
            std::cout << "Failed to deposit " << amount << " to " << accObj << std::endl;
    }
}

// withdraw amount from each account object of Account class vector
void withdraw(std::vector<Account> &accVec, double amount) {
    std::cout << "\n=============== Withdrawing from Accounts ===============" <<std::endl;
    
    for (auto &accObj: accVec) {
        if (accObj.withdraw(amount))
            std::cout << "Withdrew " << amount << " from " << accObj << std::endl;
        else
            std::cout << "Failed to Withdrew " << amount << " from " << accObj << std::endl;
    }
}

//============================================
// Utility helper functions for SavingAccount class
//============================================

// displays Account objects of a vector of account objects
void display(const std::vector<SavingAccount> &accVec) {
    std::cout << "\n============== Savings Accounts Details ================" << std::endl;
 
    for (const auto &accObj: accVec) {
        std::cout << accObj << std::endl;
    }
}

// deposit new amount to each Account object of Account Vector
void deposit(std::vector<SavingAccount> &accVec, double amount) {
    std::cout << "\n============= Depositing to Savings Accounts ==============" << std::endl;

    for (auto &accObj: accVec) {
        if(accObj.deposit(amount)) 
            std::cout << "Deposited " << amount << " to " << accObj << std::endl;
        else 
            std::cout << "Failed to deposit " << amount << " to " << accObj << std::endl;
    }
}

// withdraw amount from each account object of Account class vector
void withdraw(std::vector<SavingAccount> &accVec, double amount) {
    std::cout << "\n============== Withdrawing from Savings Accounts ===============" <<std::endl;
    
    for (auto &accObj: accVec) {
        if (accObj.withdraw(amount))
            std::cout << "Withdrew " << amount << " from " << accObj << std::endl;
        else
            std::cout << "Failed to Withdrew " << amount << " from " << accObj << std::endl;
    }
}

//============================================
// Utility helper functions for Checking Account class
//============================================

// displays Account objects of a vector of Checking Account objects
void display(const std::vector<CheckingAccount> &accVec) {
    std::cout << "\n============== Checking Accounts Details ================" << std::endl;
 
    for (const auto &accObj: accVec) {
        std::cout << accObj << std::endl;
    }
}

// deposit new amount to each Account object of Checking Account Vector
void deposit(std::vector<CheckingAccount> &accVec, double amount) {
    std::cout << "\n============= Depositing to Checking Accounts ==============" << std::endl;

    for (auto &accObj: accVec) {
        if(accObj.deposit(amount)) 
            std::cout << "Deposited " << amount << " to " << accObj << std::endl;
        else 
            std::cout << "Failed to deposit " << amount << " to " << accObj << std::endl;
    }
}

// withdraw amount from each account object of Checking Account class vector
void withdraw(std::vector<CheckingAccount> &accVec, double amount) {
    std::cout << "\n============== Withdrawing from Checking Accounts ===============" <<std::endl;
    
    for (auto &accObj: accVec) {
        if (accObj.withdraw(amount))
            std::cout << "Withdrew " << amount << " from " << accObj << std::endl;
        else
            std::cout << "Failed to Withdrew " << amount << " from " << accObj << std::endl;
    }
}

//============================================
// Utility helper functions for TrustAccount class
//============================================

// displays Account objects of a vector of Trust account objects
void display(const std::vector<TrustAccount> &accVec) {
    std::cout << "\n============== Trust Accounts Details ================" << std::endl;
 
    for (const auto &accObj: accVec) {
        std::cout << accObj << std::endl;
    }
}

// deposit new amount to each Account object of Account Vector
void deposit(std::vector<TrustAccount> &accVec, double amount) {
    std::cout << "\n============= Depositing to Trust Accounts ==============" << std::endl;

    for (auto &accObj: accVec) {
        if(accObj.deposit(amount)) 
            std::cout << "Deposited " << amount << " to " << accObj << std::endl;
        else 
            std::cout << "Failed to deposit " << amount << " to " << accObj << std::endl;
    }
}

// withdraw amount from each account object of Trust Account class vector
void withdraw(std::vector<TrustAccount> &accVec, double amount) {
    std::cout << "\n============== Withdrawing from Trust Accounts ===============" <<std::endl;
    
    for (auto &accObj: accVec) {
        if (accObj.withdraw(amount))
            std::cout << "Withdrew " << amount << " from " << accObj << std::endl;
        else
            std::cout << "Failed to Withdrew " << amount << " from " << accObj << std::endl;
    }
}

