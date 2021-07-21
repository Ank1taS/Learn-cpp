//TODO          Passing arguments to base class constructor ie calling overloaded Constructor of base class from overloaded Constructor of Derrive

#include <iostream>

class Base {
    // attributes
    int baseValue;

public:
    // default constructor
    Base(): baseValue {0} {
        std::cout << "Base no-args constructor" << std::endl;
    }

    // overloaded constructor
    Base(int baseValue)
        : baseValue {baseValue} {
            std::cout << "Base (int) overloaded constructor" << std::endl;
    }

    // destructor
    ~Base() {
        std::cout << "Base Destructor." << std::endl;
    }
};

class Derived: public Base {
    // attribute
    int derivedValue;
    
public:
    // default constructor
    Derived(): derivedValue {0} {               // : base(), derivedValue {0}
        std::cout << "Derived no-args constructor" << std::endl;
    }

    // overloaded constructor
    Derived(int derivedValue)                   // : base(), derivedValue {derivedValue}
        : derivedValue {derivedValue} {         
        std::cout << "Derived (int) overloaded constructor" << std::endl;
    }

    // overloaded constructor - 2 parameters
    Derived(int baseValue, int derivedValue)
        : Base(baseValue), derivedValue {derivedValue} {

        std::cout << "Derived (int, int) overloaded constructor" << std::endl;
        }

    // destructor
    ~Derived() {
        std::cout << "Derived Destructor." << std::endl;
    }

};


int main() {
    Base obj1;
    Base obj2{100};

    Derived obj3;
    Derived obj4{1000};
    Derived obj5{10, 20};

    return 0;
}

