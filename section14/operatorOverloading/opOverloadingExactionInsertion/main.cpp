//Todo      exaction-insertion operator overloading
//Todo      main.cpp

#include "header.h"

int main() {
    MyString larry {"Larry"};
    MyString moe {"Moe"};
    MyString curly;

    std::cout << "Enter the third stooge's name: ";
    std::cin  >> curly;

    std::cout << "The three stooges are " << larry  << moe << curly << std::endl;

    std::cout << "\nEnter the three stooges names separated by a space: ";
    std::cin  >> larry >> moe >> curly;

    std::cout << "The three stooges are " << larry << ", " << moe << ", and " << curly << std::endl;

    return 0;
}
