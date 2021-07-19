//Todo          challenge excercise solution - using overloading operator as member function
//Todo          header.h

#ifndef _HEADER_H_
#define _HEADER_H_

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
    
    // Overloaded operator member methods 
    MyString operator-() const;                           // -    operator overloading - make lowercase
    bool operator==(const MyString &) const;           // ==   operator overloading - equals
    bool operator!=(const MyString &) const;           //. !=  operator overloading - not equals
    bool operator<(const MyString &) const;           //  <   operator overloading - less than
    bool operator>(const MyString &) const;           //  >   operator overloading - more than
    MyString operator+(const MyString &) const;           //  +   operator overloading - concatenate
    MyString &operator+=(const MyString &);                 // =+   operator overloading - concat and assign
    MyString operator*(int ) const;                       //. *   operator overloading - repeat s2 n times
    MyString &operator*=(int );                             //. *=  operator overloading - repeat s2 n times and assign
    MyString &operator++();                                 //  ++  operator overloading - pre increment
    MyString operator++(int );                             //  ++  operator overloading - post increment

    friend std::ostream &operator<<(std::ostream &, const MyString &);             //  <<  operator overloading - insertion operator
    friend std::istream &operator>>(std::istream &, MyString &);                   //  >>  operator overloading - extraction operator
};

#endif

