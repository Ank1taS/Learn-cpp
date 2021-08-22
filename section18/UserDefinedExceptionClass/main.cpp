    
// Creating multiple exception class 
// Miles per Gallon 

#include <iostream>
#include <string>

class DevideByZeroException {
public:
    void showException() const {
        std::cerr << "Sorry, you can't divide by zero" << std::endl;
    }
};

class NegativeValueException {
public:
    void showException() const {
        std::cerr << "Sorry, one of your parameters is negative" << std::endl;
    }
};

double calculateMpg(int miles, int gallons) {
    if (gallons == 0) {
        throw DevideByZeroException();          // throwing DevideByZeroException class anonymous object
    }

    if (miles <0 || gallons < 0) {
        throw NegativeValueException();         // throwing NegativeValueException class anonymous object
    }

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

    catch (const DevideByZeroException &ex) {
        ex.showException();
    }

    catch (const NegativeValueException &ex) {
        ex.showException();
    }
    
    std::cout << "Bye" << std::endl;

    return 0;
}

