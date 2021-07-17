//Todo      Operator overloading as non-member (global) methods 
//Todo      header.h

#ifndef _HEADER_H
#define _HEADER_H

#include <iostream>

class MyString {
    // attributes
    char *str;

    friend MyString operator- (const  MyString &);                      // overloaded -  operator (to convert string to upper case)
    friend bool     operator==(const  MyString &, const MyString &);    // overloaded == operator (to compare 2 object / strings) 
    friend MyString operator+ (const  MyString &, const MyString &);    // overloaded +  operator (to concart 2 object / strings)

public:
    // member methords
    MyString (const char *str = nullptr);                               // default constructor
    MyString (const MyString &);                                        // copy constructor
    MyString (MyString &&) noexcept;                                    // move constructor
    ~MyString();                                                        // destructor

    MyString &operator=(const MyString &);                              // copy assignment
    MyString &operator=(MyString &&) noexcept;                          // move assignment

    void display() const;                                               // getter
};
#endif
