//* problem without weak pointer
//* With shared ponter (ownership) circular reference occures and destuctor never called and results memory leak

#include <iostream>
#include <memory>

class Y;    // forward declaration

class X {
    // attribute
    std::shared_ptr<Y> yptr;

public:
    // constructor
    X() {
        std::cout << "X class Constructor called..." << std::endl;
    }

    // destructor - due to circular reference never called
    ~X() {
        std::cout << "X class Destructor called..." << std::endl;
    }

    // setter
    void setY(std::shared_ptr<Y> &ref) {
        yptr = ref;
    }
};

class Y {
    // attribute
    std::shared_ptr<X> xptr;

public:
    // constructor
    Y() {
        std::cout << "Y class Constructor called..." << std::endl;
    }

    // destructor - due to circular reference never called
    ~Y() {
        std::cout << "Y class Destructor called..." << std::endl;
    }

    // setter
    void setX(std::shared_ptr<X> &ref) {
        xptr = ref;
    }
};

int main() {
    std::shared_ptr<X> xpointer = std::make_shared<X> ();
    std::shared_ptr<Y> ypointer = std::make_shared<Y> ();

    xpointer->setY(ypointer);
    ypointer->setX(xpointer);

    // due to circular reference bet X and Y class, their shared pointer never deallocated from heap
    // destructor never called and mempry leaked
    
    return 0;
}

