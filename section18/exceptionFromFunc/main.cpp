// Throwing exception from a function
// Miles per Gallon - Function

#include <iostream>

double calculateMpg(int miles, int gallons) {
    if (gallons == 0)
        throw 0;
    return static_cast<double>(miles) / gallons;
}

int main() {    
    int miles {};
    int gallons {};
    double milesPerGallon {};   
    
    std::cout << "Enter the miles: ";
    std::cin >> miles;
    std::cout << "Enter the gallons: ";
    std::cin >> gallons;
    try {
        milesPerGallon = calculateMpg(miles, gallons);
        std::cout << "Result: " << milesPerGallon << std::endl;
    }
    catch (int &ex) {
        std::cerr << "Tried to divide by zero" << std::endl;
    }
    std::cout << "Bye" << std::endl;

    return 0;
}

