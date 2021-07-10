// shallow copy constuctor and its demerits

#include <iostream>

class Shallow {
    // atributes
    int *data;

public:
    // methods

    Shallow(int data = 10);     // default constructor
    Shallow(const Shallow &);   // copy constructor
    ~Shallow();                 // destructor

    void setValue(int value){   // modifies value that data pointer points
        *data = value;
    }         
    int getValue(){             // returns value pointed by data
        return *data;
    }             
};

// default constructor definition
Shallow::Shallow (int data) {
    this->data  =  new int;
    *this->data =  data;       // *(this->data) = data

    std::cout << "default counstructor is called...." << std::endl;
}

// copy constructor definition
Shallow::Shallow (const Shallow &obj) 
    : data {obj.data} {
    std::cout << "Copy counstructor is called...." << std::endl;
}

// destructor definition
Shallow::~Shallow () {
    delete data;
    std::cout << "Destructor is called...." <<std::endl;
}
// display method
void display(Shallow obj) {
    std::cout << "data = " << obj.getValue() << std::endl;
}

int main() {
    Shallow object1(200);
    Shallow object2 {object1};
    display(object1);

 //   display(object2);

    // object2.setValue(500);
    // display(object1);
    // display(object2);

    return 0;
}