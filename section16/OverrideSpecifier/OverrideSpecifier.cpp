// section 16
// override specifier in overriden virtual function in Derived class

#include <iostream>
#include <vector>

class Base {
public:
    virtual void massage() const{
        std::cout << "Base::massage." << std::endl;
    }

    virtual ~Base() {
        std::cout << "Base::Destructor." << std::endl;
    }
};

class Derived: public Base {
public:
    // here base class and Derived class massage mismatched hence redefinition happens and staticaly bounded . 
    // so every time massage() is called using base class pointer, base class massage() will be called and no dynamic bound will happen
    // although virtual keyword is there
    // virtual void massage() {            
    //     std::cout << "Derived::massage." << std::endl;  
    // }

    // override specifier ensures massage() prototypes matches base class massage()
    virtual void massage() const override{            
        std::cout << "Derived::massage." << std::endl;  
    }

    virtual ~Derived() {
        std::cout << "Derived::Destructor." << std::endl;
    }
};

int main() {
    Base *p1 = new Base();
    p1->massage();

    Derived *p2 = new Derived();
    p2->massage();

    Base *p3 = new Derived();
    Base *p4 = new Derived();
    Base *p5 = new Derived();
    Base *p6 = new Derived();

    std::cout << "\n========Vector of pointers=========" << std::endl;
    std::vector<Base *> ptrVec {p1, p3, p4, p5, p6, p3, p1};
    for (auto const &ref: ptrVec) {
        ref->massage();
    }

    std::cout << "===========Clean up===========" << std::endl;
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
    delete p6;
    
    return 0;
}
