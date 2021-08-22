//* Default catch handler
//* Miles per Gallon - Function - Rethrow


#include <iostream>

int main() {    
    int miles {};
    int gallons {};
    double milesPerGallon {};
    
    std::cout << "Enter the miles driven: ";
    std::cin >> miles;
    std::cout << "Enter the gallons used: ";
    std::cin >> gallons;
    
    try {
        if (gallons == 0) {
            throw gallons;              // throwing integer
        }
        else if (miles < 0 || gallons < 0) {
            throw "You can not have negative miles or gallons";     // throwing char
        }
        else if (gallons > 1000) {
            throw std::string {"Huh"};  // throwing string
        }
        else if(gallons > miles) {
            throw 0.0;                  // throwing a float
        }
    
        milesPerGallon = static_cast<double>(miles) / gallons;
        std::cout << "Result: " << milesPerGallon << std::endl;
    }
    catch (int ex) {
        std::cout << "Sorry, you can't divide by zero" << std::endl;
    }
    catch (const char *ex) {    // what happens if you don't have this but throw string
        std::cout << ex << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error" << std::endl;
        throw;
    }
    std::cout << "Bye" << std::endl;
    return 0;
}

