//Todo          challenge excercise solution - using overloading operator as non-member function / global function
//Todo          header.h

#ifndef _HEADER_H
#define _HEADER_H

#include <iostream>

class MyString {
    // attributes
    char *str;

public:
    // methods
    MyString (const char *str = nullptr);                   // default constructor
    ~MyString();                                            // destructor
    MyString (const MyString &);                            // copy constructor
    MyString (MyString &&) noexcept;                        // move constructor

    MyString &operator=(const MyString &);                  // copy assignment
    MyString &operator=(MyString &&)noexcept;               // move assignment
    
    // Overloaded operator  as non-member methods 
    friend MyString operator-(const MyString &);                            // -    operator overloading - make lowercase
    friend bool operator==(const MyString &, const MyString &);             // ==   operator overloading - equals
    friend bool operator!=(const MyString &, const MyString &);             //. !=  operator overloading - not equals
    friend bool operator<(const MyString &, const MyString &);              //  <   operator overloading - less than
    friend bool operator>(const MyString &, const MyString &);              //  >   operator overloading - more than
    friend MyString operator+(const MyString &, const MyString &);          //  +   operator overloading - concatenate
    friend MyString &operator+=(MyString &, const MyString &);              // =+   operator overloading - concat and assign
    friend MyString operator*(const MyString &, int);                       //. *   operator overloading - repeat s2 n times
    friend MyString &operator*=(MyString &, int);                           //. *=  operator overloading - repeat s2 n times and assign
    friend MyString &operator++(MyString &);                                //  ++  operator overloading - pre increment
    friend MyString operator++(MyString &, int);                      //  ++  operator overloading - post increment

    friend std::ostream &operator<<(std::ostream &, const MyString &);      //  <<  operator overloading - insertion operator
    friend std::istream &operator>>(std::istream &, MyString &);            //  >>  operator overloading - extraction operator
};

#endif

