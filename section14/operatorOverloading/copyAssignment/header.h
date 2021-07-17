//! copy assignment
//! header.h 

#ifndef _HEADER_H_
#define _HEADER_H_

class MyString {
    // attributes
    char *str;                                  // pointer to char[] that holds a C-style string

public:
    //Methods
    MyString(const char *str = nullptr);        // default constructor
    ~MyString();                                // destructor
    MyString(const MyString &);                 // deep copy constructor
    MyString &operator=(const MyString &);      // copy assignment

    void display() const;                       // getter

};

#endif
