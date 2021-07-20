//Todo      protected members and class access

#include <iostream>

class Base {
    // Note friends of Base have access to all 

    int x;

protected:
    int y;

public:
    int z;

    // default constructor
    Base(int x = 10, int y = 20, int z = 30) 
        : x {x}, y {y}, z{z} {
    }       

    // getter -  
    // member method has access to all
    void display() const {
        std::cout << "x = " << x  // ok - 
        << "\t y = " << y 
        << "\t z = " << z << std::endl; 
    }
};

class Derrive: public Base {
    // Note friends of Derived have access to only what Derived has access to

    // as visibility mode is public, 
                                    // z will be public
                                    // y will be protected
                                    // x will not be accessible but inheritted
    
public:
//     Derrive() {
//   //      Base::Base();
//     }

    // setter
    void setValue() {
        // x = 100;                    // compiler error
        y = 200;
        z = 300;                 
    }

};

int main() {

    std::cout << "=== Base member access from base objects ===========" << std::endl;
    
    Base baseObj;
    baseObj.display();
    // baseObj.x = 50;              // compiler error as x is private in base 
    // baseObj.y = 60;              // compiler error as y is private in base 
    baseObj.z = 70;                 // ok
    baseObj.display();

    std::cout << "=== Base member access from derrive objects ===========" << std::endl;
    
    Derrive derriveObj;
    
    derriveObj.display();
    derriveObj.setValue();
    // derriveObj.x = 50;             // compiler error as x is private in Derrive
    // derriveObj.y = 60;             // compiler error as y is protected in Derrive
    derriveObj.z = 70;                // ok
    derriveObj.display();

    return 0;
}
