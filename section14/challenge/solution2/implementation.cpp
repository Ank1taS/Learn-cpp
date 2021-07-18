//Todo      challenge excercise solution - using overloading operator as member function
//Todo      implementation.cpp

#include "header.h"
#include <cstring>
#include <cctype>

// default constructor
MyString::MyString(const char *str) 
        : str {nullptr} {

    if (str == nullptr) {
        std::cout << "Default constructor for nullpointer" << std::endl;

        this->str  = new char[1];
        *this->str = '\0';
    }
    else {
        std::cout << "Default constructor for -" << str << std::endl;

        this->str = new char[strlen(str) + 1];
        strcpy(this->str, str);
    }
}

// destructor
MyString::~MyString() {
    if (str == nullptr) {
        std::cout << "destructor is called for : nullpointer" << std::endl;
    }
    else {
        std::cout << "destructor is called for : " << str << std::endl;
    }

    delete [] str;
}

// copy constructor
MyString::MyString(const MyString &sourceObj) 
        : MyString {sourceObj.str} {
    std::cout << "Copy constructor called for " << sourceObj.str << std::endl;
}

// move constructor
MyString::MyString(MyString &&sourceObj) noexcept 
        : str {sourceObj.str} {
    std::cout << "Move constructor called for " << sourceObj.str << std::endl;
    sourceObj.str = nullptr;
}

// copy assignment
MyString &MyString::operator=(const MyString &sourceObj) {
    std::cout << "Copy assignment called for " << sourceObj.str << std::endl;

    if (str == sourceObj.str) {
        return *this;
    }
    delete [] str;
    str = new char [strlen(sourceObj.str) + 1];
    strcpy(str, sourceObj.str);
    return *this;
}

// move assignment
MyString &MyString::operator=(MyString &&sourceObj) noexcept {
    std::cout << "Move assignment for " << sourceObj.str << std::endl;
    
    if (str == sourceObj.str) {
        return *this;
    }

    delete [] str;
    str = sourceObj.str;
    sourceObj.str = nullptr;
    return *this;
}

//  -   operator overloading - make lowercase
//  Returns the lowercase version of the object's string
MyString operator-(const MyString &sourceObj) {
    char *buff = new char[strlen(sourceObj.str) + 1];
    strcpy(buff, sourceObj.str);

    for (size_t i = 0; i < strlen(buff); ++i) {
        buff[i] = tolower(buff[i]);
    }

    MyString temp {buff};
    delete [] buff;

    return temp;
}

// ==   operator overloading - equals
// Returns true if the two strings are equal
bool operator==(const MyString &lhs, const MyString &rhs) {
    return (strcmp(lhs.str, rhs.str) == 0);
}

//. !=  operator overloading - not equals
// Returns true if the two strings are not equal
bool operator!=(const MyString &lhs, const MyString &rhs) {
    return (strcmp(lhs.str, rhs.str) != 0);
}

//  <   operator overloading - less than
// Returns true if the lhs string is lexically less than the rhs string
bool operator<(const MyString &lhs, const MyString &rhs) {
    return (strcmp(lhs.str, rhs.str) < 0);
}

//   >  operator overloading - more than
// Returns true if the lhs string is lexically greater than the rhs string
bool operator>(const MyString &lhs, const MyString &rhs) {
    return (strcmp(lhs.str, rhs.str) > 0);
}

//  +   operator overloading - concatenate
// + Returns an object that concatenates the lhs and rhs
MyString operator+(const MyString &lhs, const MyString &rhs) {
    char *buff = new char[strlen(rhs.str) + strlen(lhs.str) + 1];
    strcpy(buff, lhs.str);
    strcat(buff, rhs.str);

    MyString temp {buff};
    delete [] buff;
    return temp;
}

// =+   operator overloading - concat and assign
//      concatenate the rhs string to the lhs string and store the result in lhs object
MyString &operator+=(MyString &lhs, const MyString &rhs) {
    lhs = lhs + rhs;    // calling +operator overloaded function
    return lhs; 
}

//. *   operator overloading - repeat
//. s2 = s2 * ntimes or s1 = s2 * ntimes
MyString operator*(const MyString &sourceObj, int repeatTime) {
    MyString temp;

    for (int i = 0; i < repeatTime; ++i) {
        temp = temp + sourceObj; 
    }
    return temp;
}

//. *=  operator overloading - repeat s2 n times and assign
// repeat the string on the lhs n times and store the result back in the lhs object
MyString &operator*=(MyString &sourceObj, int repeat) {
    sourceObj = sourceObj * repeat;
    return sourceObj;
}

//  ++  operator overloading - pre increment
//  converts all characters of Mystring Object to uppercase
MyString &operator++(MyString &sourceObj) {
    for (size_t i = 0; i < strlen(sourceObj.str) ; ++i) {
        sourceObj.str[i] = toupper(sourceObj.str[i]);
    }
    return sourceObj;    
} 

//  ++  operator overloading - post increment
//  converts all characters of Mystring Object to uppercase and store in another
MyString operator++(MyString &sourceObj, int n) {
    MyString temp {sourceObj};
    ++sourceObj;            //*this = ++(*this);
    return temp;    
}

//  <<  operator overloading - insertion operator
std::ostream &operator<<(std::ostream &os, const MyString &rhs) {
    os << rhs.str;
    return os;
}

//  >>  operator overloading - extraction operator
std::istream &operator>>(std::istream &is, MyString &rhs) {
    char *buff = new char[100];
    is >> buff;
    rhs = MyString(buff);
    delete [] buff;
    return is;
}


