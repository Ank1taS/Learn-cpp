//Todo      Operator overloading as non-member (global) methods 
//Todo      implementation.cpp

#include <cstring>
#include <cctype>
#include "header.h"


// Default constructor
MyString::MyString (const char *str) 
        : str {nullptr} {
    if (str == nullptr) {
        this->str  = new char[1];
        *this->str = '\0';
    }
    else {
        this->str = new char[strlen(str) + 1];
        strcpy (this->str, str);
    }
    std::cout << "default constructor is called for : " << this->str << std::endl;
}

// Destructor
MyString::~MyString() {
    if (str == nullptr) {
        std::cout << "destructor is called for : nullptr" << std::endl;
    }
    else {
        std::cout << "destructor is called for : " << this->str << std::endl;
    }
    delete [] str;
}

// copy constructor - delegating constructor
MyString::MyString(const MyString &sourceObj) 
        : MyString {sourceObj.str} {
    std::cout << "copy constructor is called for : " << this->str << std::endl;
}

// Move constructor - delegating constructor
MyString::MyString(MyString &&sourceObj) noexcept 
        : str {sourceObj.str} {
    std::cout << "Move constructor is called for : " << this->str << std::endl;
    sourceObj.str = nullptr;
}

// copy assignment
MyString &MyString::operator=(const MyString &sourceObj) {
    std::cout << "copy assignment is called for : " << str << std::endl;

    if (this == &sourceObj) {
        return *this;
    }
    delete [] this->str;
    this->str = new char [strlen(sourceObj.str) + 1];
    strcpy (this->str, sourceObj.str);
    return *this;
}

// move assignment
MyString &MyString::operator=(MyString &&sourceObj) noexcept {
    std::cout << "Move assignment is called for : " << this->str << std::endl;

    if (this == &sourceObj) {
        return *this;
    }
    delete [] this->str;
    this->str     = sourceObj.str;
    sourceObj.str = nullptr;
    return *this;
}

void MyString::display () const {
    std::cout << str << " : " << strlen(str) << std::endl;
}

// overloaded - operator (to convert string to upper case)
MyString operator-(const MyString &sourceObj) {

    char *buff = new char[strlen(sourceObj.str) + 1];
    strcpy(buff, sourceObj.str);

    for(auto i = 0; i < strlen(buff); ++i) {
        buff[i] = toupper(buff[i]);
    }

    MyString temp {buff};
    delete [] buff;

    return temp;
}

// overloaded == operator (to compare 2 strings)
bool operator==(const MyString &sourceObj1, const MyString &sourceObj2) {
    return(strcmp(sourceObj1.str, sourceObj2.str) == 0);
}

// overloaded + operator (to concart 2 Mystring objects)
MyString operator+(const MyString &sourceObj1, const MyString &sourceObj2) {
    
    char *buff = new char[strlen(sourceObj1.str) + strlen(sourceObj2.str) + 1];
    
    strcpy(buff, sourceObj1.str);
    strcat(buff, sourceObj2.str);

    MyString temp {buff};
    delete [] buff;

    return temp;
}

