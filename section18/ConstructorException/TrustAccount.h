//* section15 challenge
//* TrustAccount header file
//Trust account class to the Account hierarchy

// A Trust account has a name, a balance, and an interest rate
// The Trust account deposit works just like a savings account deposit.
// However, any deposits of $5000.00 or more will receive a $50.00 bonus deposited to the account.
    
// The Trust account withdrawal should only allow 3 withdrawals per year and each of these must be less than 20% of the account balance.
// the 4th withdrawal fails :)

#ifndef _TRUSTACCOUNT_H_
#define _TRUSTACCOUNT_H_

#include "SavingAccount.h"

class TrustAccount: public SavingAccount{
    // overloaded non-member extraction operator
    friend std::ostream &operator<<(std::ostream &, const TrustAccount &);

    static constexpr const char *defName                = "Unname TrustAccount";
    static constexpr double     defBalance              = 0.0;
    static constexpr double     defInterestRate         = 0.0;
    static constexpr double     defThresholdAmount      = 5000.0;
    static constexpr double     defBonus                = 50.0;
    static constexpr double     defMaxWithdrawPercent   = 0.2;
    static constexpr int        defMaxWithdrawTimeLimit = 3;

protected:
    int withdrawCount;

public:
    TrustAccount(std::string name = defName, double balance = defBalance, double interestRate = defInterestRate);   // default constructor
    
    virtual void print(std::ostream &) const override;      // overriden virtual print()
    virtual bool deposit(double) override;                  // overriden virtual deposit() - Deposits of $5000.00 or more will receive $50 bonus
    virtual bool withdraw(double) override;                 // overriden virtual withdraw()- Only allowed maximum of 3 withdrawals, each can be up to a maximum of 20% of the account's value
    virtual ~TrustAccount() = default;                      // virtual destructor
};

#endif
