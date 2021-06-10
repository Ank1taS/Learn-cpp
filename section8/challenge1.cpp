// providing changes to cents as instucted

#include <iostream>

int main() {
    int cent {}, dollar {}, quarters{}, dimes {}, nickels {}, pennies {}, temp {};
    const int dollarValue {100}, quartersValue {25}, dimesValue {10}, nickelsValue {5};
    
    std::cout << "enter an amount in cents: ";
    std::cin >> cent;

    dollar = cent / dollarValue;
    temp = cent % dollarValue;
    std::cout << "\ndollars\t : " << dollar;

    quarters = temp / quartersValue;
    temp %= quartersValue;
    std::cout << "\nquarters : " << quarters;

    dimes = temp / dimesValue;
    temp %= dimesValue;
    std::cout << "\ndimes\t : " << dimes;

    nickels = temp / nickelsValue;
    temp %= nickelsValue;
    std::cout << "\nnickels\t : " << nickels;

    std::cout << "\npennies\t : " << temp << std::endl;
    
    return 0;
}