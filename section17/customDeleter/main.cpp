// Custom deleter


#include <iostream>
#include <memory>

class Test {
    // attribute
    int data;

public:
    // default constructor
    Test(int data = 0)
        : data {data} {
        std::cout << "Constructor called for - " << data << std::endl;
    }

    // destructor
    ~Test() {
        std::cout << "Destructor called for  - " << data << std::endl;
    }

    // getter
    int getData() {
        return data;
    }
};

// custom deleter
void myDelete(Test *ptr) {
    std::cout << "Custom deleter for " << ptr->getData() << std::endl;
    
    delete ptr;
}

int main() {
    {
        // using function
    //    std::shared_ptr<Test> ptr1 = std::make_shared<Test> (100);
        std::shared_ptr<Test> ptr1 {new Test{100}, myDelete};
    }

    {
        // using lamda expression
        std::shared_ptr<Test> ptr2 (new Test{500},
            [] (Test *ptr) {
                std::cout << "Lamda custom deleter for " << std::endl;
                delete ptr;
            });
    }

    return 0;
}

