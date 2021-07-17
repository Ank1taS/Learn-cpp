//! copy assignment 
//! main.cpp 

#include "header.h"

int main() {
    MyString empty;
    MyString a {"Ankita Sahoo"};
    a.display();
    MyString b {a};
    b.display();
    b = "Hello!";
    b.display();
    
    return 0;
}
