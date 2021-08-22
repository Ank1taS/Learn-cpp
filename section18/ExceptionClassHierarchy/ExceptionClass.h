// exception class

#ifndef _EXCEPTIONCLASS_H_
#define _EXCEPTIONCLASS_H_

#include <exception>

class IllegalBalanceException : public std::exception {
public:
    IllegalBalanceException() noexcept  = default;
    ~IllegalBalanceException() = default;

    virtual const char* what() const noexcept {
        return "Illegal balance exception";
    }
};

#endif
