//* section15 challenge
//* TrustAccount implementation file
//Trust account class to the Account hierarchy

// A Trust account has a name, a balance, and an interest rate
// The Trust account deposit works just like a savings account deposit.
// However, any deposits of $5000.00 or more will receive a $50.00 bonus deposited to the account.
    
// The Trust account withdrawal should only allow 3 withdrawals per year and each of these must be less than 20% of the account balance.
// the 4th withdrawal fails :)

#include "TrustAccount.h"
#include "InsufficentFundsException.h"

// default constructor
TrustAccount::TrustAccount(std::string name, double balance, double interestRate)
    : SavingAccount {name, balance, interestRate}, withdrawCount {0} {}

// redefined deposit method - Deposits of $5000.00 or more will receive $50 bonus
bool TrustAccount::deposit(double amount) {
    if (amount >= defThresholdAmount) 
        amount += defBonus;
    
    return SavingAccount::deposit(amount);
}

// Only allowed maximum of 3 withdrawals, each can be up to a maximum of 20% of the account's value
bool TrustAccount::withdraw(double amount) {
    if (withdrawCount >= defMaxWithdrawTimeLimit) 
        return false;
    else if (amount > balance * defMaxWithdrawPercent)
        throw InsufficentFundException();

    ++withdrawCount;
    return Account::withdraw(amount);
}

// overriden print()
void TrustAccount::print(std::ostream &os) const {
    os << "[Trust Account: " << name << ": " << balance << ", " << interestRate << "%, withdrawals: " << withdrawCount <<  "]";
}

