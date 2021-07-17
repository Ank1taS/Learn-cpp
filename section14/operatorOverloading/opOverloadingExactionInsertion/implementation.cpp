//Todo      exaction-insertion operator overloading
//Todo      implementation.cpp

#include "header.h"
#include <cstring>

// default constructor 
MyString::MyString(const char *str) 
        : str {nullptr} {
    if (str == nullptr) {
        this->str  = new char[1];
        *this->str = '\0';
    }
    else {
        this->str = new char[strlen(str) + 1];
        strcpy(this->str, str);
    }
}

// destructor
MyString::~MyString() {
    delete [] str;
}

// copy constructor - delegating constructor
MyString::MyString(const MyString &sourceObj)
        : MyString(sourceObj.str) {
//    std::cout << "copy constructor for - " << this->str << std::endl;
}

// move constructor
MyString::MyString(MyString &&sourceObj) noexcept
        : str {sourceObj.str} {
    sourceObj.str = nullptr;
//    std::cout << "move constructor for - " << this->str << std::endl;
}

// copy assignment
MyString &MyString::operator=(const MyString &sourceObj) {
//    std::cout << "copy assignment is called for : " << str << std::endl;

    if (this == &sourceObj) {
        return *this;
    }
    delete [] str;
    str = new char[strlen(sourceObj.str) + 1];
    strcpy(str, sourceObj.str);
    return *this;
}

// move assignment
MyString &MyString::operator=(MyString &&sourceObj) noexcept {
//    std::cout << "Move assignment is called for : " << str << std::endl;
    
    if (this == &sourceObj) {
        return *this;
    }
    delete [] str;
    str           = sourceObj.str;
    sourceObj.str = nullptr;
    return *this;
}

// insertion operator overloaded non-member function
std::ostream &operator<<(std::ostream &os, const MyString &sourceObj) {
    os << sourceObj.str << " : " << strlen(sourceObj.str) << std::endl;
    return os;
}

// extraction operator overloaded nob-member function
std::istream &operator>>(std::istream &is, MyString &sourceObj) {
    char *buff = new char [100];
    is >> buff;
    sourceObj = MyString {buff};
    delete [] buff;
    return is;
}

