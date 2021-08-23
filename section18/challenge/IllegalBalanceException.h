//* section challenge18
//* This exception object should be thrown from the Account class constructor if an account object is created with a negative balance.
   
#ifndef _ILLEGAL_BALANCE_EXCEPTION_H
#define _ILLEGAL_BALANCE_EXCEPTION_H

#include <exception>

class IllegalBalanceException : public std::exception {
public:
    IllegalBalanceException() noexcept = default;
    ~IllegalBalanceException() = default;

    virtual const char* what() const noexcept {
        return "Illegal Balance Exception";
    }
};

#endif
