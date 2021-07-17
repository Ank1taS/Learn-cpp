//! copy assignment
//! implementation.cpp


#include <cstring>
#include <iostream>
#include "header.h"

// default constructor
MyString::MyString (const char *str) 
        : str {nullptr} {
    if (str == nullptr) {
        this->str  = new char[1];
        *this->str = '\0';
    }
    else {
        this->str = new char[std::strlen(str) + 1];
        std::strcpy(this->str, str);
    }

    std::cout << "default constructor is called for : " << this->str << std::endl;
}

// destructor
MyString::~MyString() {
    std::cout << "destructor is called for : " << str << std::endl;
    delete [] str;
}

// copy construtor - delegating constructor
MyString::MyString(const MyString &sourceObj) 
        : MyString {sourceObj.str} { 
    std::cout << "copy constructor is called for : " << str << std::endl;
}

// // copy constructor
// MyString::MyString(const MyString &sourceObj) 
//         : str {nullptr} {
//     str = new char[std::strlen(sourceObj.str) + 1];
//     std::strcpy(str, sourceObj.str);
// }

// copy assignment
MyString &MyString::operator=(const MyString &sourceObj) {
    std::cout << "copy assignment is called for : " << str << std::endl;

    if (this == &sourceObj) {
        return *this;
    }
    else {
        delete [] this->str;
        str = new char[std::strlen(sourceObj.str) + 1];
        std::strcpy(this->str, sourceObj.str);
        return *this;
    }
}

void MyString::display() const{
    std::cout << str << " : " << std::strlen(this->str) << std::endl;
}
