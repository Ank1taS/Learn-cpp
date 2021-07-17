//! move assignment
//! implementation.cpp

#include <iostream>
#include <cstring>
#include "header.h"

// default constructor definition
MoveMyString::MoveMyString(const char *str)
    : str {nullptr} {
    if (str == nullptr) {
        this->str  = new char[1];
        *this->str = '\0';
    }
    else {
        this->str = new char[strlen(str) + 1];
        strcpy(this->str, str);
    }
    std::cout << "default constructor is called for : " << this->str << std::endl;
}

// destructor definition
MoveMyString::~MoveMyString() {
    if (str == nullptr) {
        std::cout << "destructor is called for : nullpointer" << std::endl;
    }
    else {
        std::cout << "destructor is called for : " << str << std::endl;
    }
    delete [] str;
}

// copy constructor definition
MoveMyString::MoveMyString(const MoveMyString &sourceObj)
    : MoveMyString(sourceObj.str) {
    std::cout << "copy constrcuctor is called for : " << str << std::endl;
}

// move constructor definition
MoveMyString::MoveMyString(MoveMyString &&sourceObj) noexcept
    :str {sourceObj.str} {
    std::cout << "Move constructor is called for : " << str << std::endl;
    sourceObj.str = nullptr;
}

// Copy assignment operator definition
MoveMyString &MoveMyString::operator=(const MoveMyString &sourceObj) {
    
    std::cout << "copy assignment is called for : " << str << std::endl;
    
    if (this == &sourceObj) {
        return *this;
    }
    delete [] this->str;
    this->str = new char[strlen(sourceObj.str) + 1];
    strcpy(this->str, sourceObj.str);
    return *this;
}

// move assignment operator definition
MoveMyString &MoveMyString::operator=(MoveMyString &&sourceObj) noexcept {
    std::cout << "Move assignment is called for : " << str << std::endl;

    if (this == &sourceObj) {
        return *this;
    }
    delete [] this->str;
    this->str = sourceObj.str;
    sourceObj.str = nullptr;
    return *this;
}

void MoveMyString::display() const{
    std::cout << str << " : " << std::strlen(this->str) << std::endl;
}
