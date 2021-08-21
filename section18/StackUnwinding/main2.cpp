// Stack Unwinding example

#include <iostream>

void functionA();
void functionB();
void functionC();

void functionA() {
    std::cout << "Starting function-A" << std::endl;
    functionB();
    std::cout << "Ending function-A" << std::endl;
}

void functionB() {
    std::cout << "Starting function-B" << std::endl;
    functionC();
    std::cout << "Ending function-B" << std::endl;
}

void functionC()  {
    std::cout << "Starting function-C" << std::endl;
    throw 100;
    std::cout << "Ending function-C" << std::endl; 
}

int main() {    
    
    std::cout << "Starting main" << std::endl;
    try {
        functionA();
    }
    catch (int &ex) {
        std::cout << "Caught error in main" << std::endl;
    }
    std::cout << "Finishing main" << std::endl;
    return 0;
}

