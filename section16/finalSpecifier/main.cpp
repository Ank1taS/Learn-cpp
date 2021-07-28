// Section 16
// Using final specifier in overriden method and classes

#include <iostream>

class Base {
public:
    virtual void say_hello() const {
        std::cout << "Hello - I'm a Base class object" << std::endl;
    }
};

class Derived1: public Base {
public:
    // final method
    virtual void say_hello()  const override final {       
        std::cout << "Hello - I'm a Derived1 class object" << std::endl;
    }
};

// final class
class Derived2 final: public Derived1 {
public:
    // Errror cannot override final method
    // virtual void say_hello()  const override  {       
    //     std::cout << "Hello - I'm a Another class object" << std::endl;
    // }

    // Derived2 class say_hello prototype differs from Derrived1 
    // static bindng occure and Derived2::say_hello will never be called
    virtual void say_hello() {       
        std::cout << "Hello - I'm a Derived2 class object" << std::endl;
    }
};

// error - can not inherit final base class
// class Derived3: public Derived2 {
// public:
//     virtual void say_hello() {       
//         std::cout << "Hello - I'm a Derived3 class object" << std::endl;
//     }
// };

void greetings(const Base &obj) {
    std::cout << "Greetings: ";
    obj.say_hello();
}

using namespace std;

int main() {
    Base b;
    b.say_hello();                          // Base::say_hello()
    
    Derived1 d1;                            // Derived1::say_hello()
    d1.say_hello();
    
    Derived2 d2;                            // Derived2::say_hello()
    d2.say_hello();

    // Derived3 d3;                          // Derived3::say_hello()           ERROR
    // d3.say_hello();

    Base *p1 = new Base();                  // Base::say_hello()
    p1->say_hello();
    
    Derived1 *p2 = new Derived1();          // Derived1::say_hello()             
    p2->say_hello();
    
    Base *p3 = new Derived2();              // Derived1::say_hello()    -   static binding 
    p3->say_hello();                        // Derived2::say_hello will never called as static bound happens
                                            // Base::say_hello() is not as immediate parent is Derrived1 having virtual say_hello() 
    
    // Base *p4 = new Derived3();                                               ERROR
    // p4->say_hello();

    std::cout <<  "\n========================" << std::endl;
    greetings(b);
    greetings(d1);
    greetings(d2);                          
    greetings(*p1);
    greetings(*p2);
    greetings(*p3);
    // greetings(*p4);                                                          ERROR
    
    return 0;
}

