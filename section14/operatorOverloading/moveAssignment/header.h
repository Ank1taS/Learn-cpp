//! move assignment
//! header.h

#ifndef _HEADER_H_
#define _HEADER_H_

class MoveMyString {
    // attribute
    char *str;                                          // pointer to char[] that holds a C-style string

public:
    // member methords
    MoveMyString(const char *str = nullptr);            // default constructor 
    ~MoveMyString();                                    // destructor
    MoveMyString(const MoveMyString &);                 // deep copy constructor
    MoveMyString(MoveMyString &&) noexcept;             // move constructor

    MoveMyString &operator=(const MoveMyString &);      // copy assignment
    MoveMyString &operator=(MoveMyString &&) noexcept;  // move assignment

    void display() const;                               // getter

};

#endif