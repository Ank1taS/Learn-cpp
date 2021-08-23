//* section16 challenge
//* InsufficentFundException header file - simple Account class
//* This exception object should be thrown if a withdraw results in a negative balance. This exception object is thrown from the Account withdraw method.
   
#ifndef _INSUFFICENT_FUND_EXCEPTION_H_
#define _INSUFFICENT_FUND_EXCEPTION_H_

#include <exception>

class InsufficentFundException : public std::exception {
public:
    InsufficentFundException() noexcept = default;
    ~InsufficentFundException() = default;

    virtual const char* what() const noexcept {
        return "Insufficent Fund Exception";
    }
};

#endif
