//Todo      exaction-insertion operator overloading
//Todo      header.h

#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>

class MyString {
    // attribute
    char *str;

    // friend functions
    friend std::ostream &operator<<(std::ostream &os, const MyString &sourceObj);       // insertion operator overloading
    friend std::istream &operator>>(std::istream &is, MyString &sourceObj);             // extraction operator oberloading

public:
    // methord
    MyString(const char *str = nullptr);                                                      // default constructor
    ~MyString();                                                                        // destructor
    MyString(const MyString &);                                                         // copy constructor
    MyString(MyString &&) noexcept;                                                     // move constructor

    MyString &operator=(const MyString &);                                             // copy assignment
    MyString &operator=(MyString &&) noexcept;                                         // move assignment
};

#endif

