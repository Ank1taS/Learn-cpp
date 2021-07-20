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

class Derrive: public Base {
    // attribute
    int derriveValue;

public:
    // default constructor
    Derrive(): derriveValue {0} {
        std::cout << "Derrive no-args constructor" << std::endl;
    }

    // overloaded constructor
    Derrive(int derriveValue)
        : derriveValue {derriveValue} {
        std::cout << "Derrive (int) overloaded constructor" << std::endl;
    }

    // destructor
    ~Derrive() {
        std::cout << "Derrive Destructor." << std::endl;
    }

};


int main() {
    Base obj1;
    Base obj2{100};

    Derrive obj3;
    Derrive obj4{1000};

    return 0;
}

