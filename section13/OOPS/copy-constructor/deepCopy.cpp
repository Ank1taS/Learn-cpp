// Deep copy constructor

#include <iostream>

class Deep {
    // atributes
    int *data;

public:
    // methords
    Deep(int data = 10);            // default constructor
    Deep(const Deep &);             // copy constructor
    ~Deep();                        // destructor

    void setValue(int value) {      // modifies value that data pointer points
        *data = value;
    }

    int getValue() {                // returns value pointed by data
        return *data;
    }
};

// default constructor definition
Deep::Deep(int data) {
    this->data  = new int;
    *this->data =  data;       // *(this->data) = data

    std::cout << "default counstructor is called...." << std::endl;
}

// copy constructor definition - delegation constructor
Deep::Deep(const Deep &obj) 
    : Deep(*obj.data) {

    std::cout << "Copy counstructor is called...." << std::endl;
}

// destructor definition
Deep::~Deep() {
    delete data;
    std::cout << "Destructor is called...." << std::endl;
}
// display method
void display(Deep obj) {
    std::cout << "data = " << obj.getValue() << std::endl;
}

int main() {
    Deep object1(100);

    display(object1);
    Deep object2 {object1};

    display(object2);

    object2.setValue(500);
    display(object1);
    display(object2);


    return 0;
}