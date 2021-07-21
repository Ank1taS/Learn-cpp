//Todo      working of copy contructor and overloaded copy assignment operator with inheritance

#include <iostream>

class Base {
    // attribute
    int baseValue;

public:
    // default constructor
    Base(): baseValue {0} {
        std::cout << "Base no-args constructor" << std::endl;
    }

    // overloaded base constructor
    Base(int x) 
        : baseValue {x} { 
        std::cout << "Base overloaded(int) constructor" << std::endl;
    }

    // copy constructor
    Base(const Base &sourceObj) 
        : baseValue {sourceObj.baseValue} {
        std::cout << "Base copy constructor" << std::endl;
    }

    // copy assignment
    Base &operator=(const Base &sourceObj) {
        std::cout << "Base copy assignment operator" << std::endl;
        if (this != &sourceObj) {
            baseValue = sourceObj.baseValue;
        }

        return *this;
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
    Derived(): derivedValue {0} {                       // : base(), derivedValue {0}
        std::cout << "Derived no-args constructor" << std::endl;
    }

    // overloaded constructor
    Derived(int derivedValue)                           // : base(), derivedValue {derivedValue}
        : derivedValue {derivedValue} {         
        std::cout << "Derived (int) overloaded constructor" << std::endl;
    }

    // overloaded constructor - 2 parameters
    Derived(int baseValue, int derivedValue)
        : Base(baseValue), derivedValue {derivedValue} {

        std::cout << "Derived (int, int) overloaded constructor" << std::endl;
    }

    // copy constructor
    Derived (const Derived &sourceObj) 
        : Base(sourceObj),derivedValue {sourceObj.derivedValue} {     // if base(sourceObje) is not provided then default base comstructor will be called
        std::cout << "Derived copy constructor" << std::endl;
    }

    // copy assignment overloaded-operator
    Derived &operator=(const Derived &sourceObj) {
        if (this != &sourceObj) {
            Base::operator=(sourceObj);
            derivedValue = sourceObj.derivedValue;
        }
        std::cout << "Derived copy assignment operator" << std::endl;

        return *this;
    }

    // destructor
    ~Derived() {
        std::cout << "Derived Destructor." << std::endl;
    }
};

int main() {
    Base b {100};           // Overloaded constructor
    Base b1 {b};            // Copy constructor
    b = b1;                 // Copy assignment

    Derived d {100};        // Overloaded constructor
    Derived d2{10, 20};     // Overloaded constructor
    Derived d1 {d};         // Copy constructor
    d = d1;                 // Copy assignment
    

    return 0;
}
