//TODO          constructor and destructor

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
    Derived(): derivedValue {0} {
        std::cout << "Derived no-args constructor" << std::endl;
    }

    // overloaded constructor
    Derived(int derivedValue)
        : derivedValue {derivedValue} {
        std::cout << "Derived (int) overloaded constructor" << std::endl;
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

    return 0;
}

