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

class Derrive: public Base {
    // attribute
    int derriveValue;
    
public:
    // default constructor
    Derrive(): derriveValue {0} {               // : base(), derriveValue {0}
        std::cout << "Derrive no-args constructor" << std::endl;
    }

    // overloaded constructor
    Derrive(int derriveValue)                   // : base(), derriveValue {derriveValue}
        : derriveValue {derriveValue} {         
        std::cout << "Derrive (int) overloaded constructor" << std::endl;
    }

    // overloaded constructor - 2 parameters
    Derrive(int baseValue, int derriveValue)
        : Base(baseValue), derriveValue {derriveValue} {

        std::cout << "Derrive (int, int) overloaded constructor" << std::endl;
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
    Derrive obj5{10, 20};

    return 0;
}

