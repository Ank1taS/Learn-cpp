// Shared pointer

#include <iostream>
#include <vector>
#include <memory>

class Test {
    // attribute
    int value;

public:
    // default constructor
    Test(int value = 0)
        : value {value} {
        std::cout << "constructor for - " << value << std::endl;
    }

    // destructor
    ~Test() {
        std::cout << "destructor for  - " << value << std::endl;
    }

    //getter
    int getValue() const {
        return value;
    }
};

// function to print count of shared pointer - (creates a copy of pointer / parameter, so copy constructor called)
void displayCount(std::shared_ptr<Test> obj) {
    std::cout << "obj  - " << obj->getValue() << ",count - " << obj.use_count() << std::endl; 
}

int main() {

    // integer pointer
    
    std::shared_ptr<int> p1 {new int {100}};
    std::shared_ptr<int> p2 = std::make_shared<int> (200);      // more efficient
    std::shared_ptr<int> p3;
    p3 = p2;

    std::cout << "Integer ponters\n" << std::endl;
    std::cout << "p1 = " << *p1 << ", count = " << p1.use_count() << std::endl;
    std::cout << "p2 = " << *p2 << ", count = " << p2.use_count() << std::endl;
    std::cout << "p3 = " << *p3 << ", count = " << p3.use_count() << std::endl;

    p1.reset();
    p1 = p2;

    std::cout << "p1 = " << *p1 << ", count = " << p1.use_count() << std::endl;
    std::cout << "p2 = " << *p2 << ", count = " << p2.use_count() << std::endl;
    std::cout << "p3 = " << *p3 << ", count = " << p3.use_count() << std::endl;

    p3.reset();
    
    std::cout << "p1 = " << *p1 << ", count = " << p1.use_count() << std::endl;
    std::cout << "p2 = " << *p2 << ", count = " << p2.use_count() << std::endl;
    std::cout << "p3 =  can't dereferenced, count = " << p3.use_count() << std::endl;

    std::cout << "\n====================================================================" << std::endl;
    std::cout << "\nShared Class ponters\n" << std::endl;
    
    // Shared class pointers
    std::shared_ptr<Test> ptr {new Test {1000}};
    std::shared_ptr<Test> ptr1 = std::make_shared<Test> (2000);     // more efficient

    std::cout << "ptr  - " << ptr->getValue()  << ", count - " << ptr.use_count()  << std::endl;
    std::cout << "ptr1 - " << ptr1->getValue() << ", count - " << ptr1.use_count() << std::endl;
    displayCount(ptr);
    std::cout << "ptr  - " << ptr->getValue() << ", count - " << ptr.use_count() << std::endl;

    {
        std::shared_ptr<Test> ptr2 = ptr1;    
        
        std::cout << "\nptr1 - " << ptr1->getValue() << ", count - " << ptr1.use_count() << std::endl;
        std::cout << "ptr2 - "   << ptr2->getValue() << ", count - " << ptr2.use_count() << std::endl;

        {
            std::shared_ptr<Test> ptr3 = ptr2;      // copy constructor
            
            std::cout << "\nptr1 - " << ptr1->getValue() << ", count - " << ptr1.use_count() << std::endl;
            std::cout << "ptr2 - "   << ptr2->getValue() << ", count - " << ptr2.use_count() << std::endl;
            std::cout << "ptr3 - "   << ptr3->getValue() << ", count - " << ptr3.use_count() << std::endl;
            
            ptr1.reset();

            std::cout << "\nptr1 - can't dereferenced , count - " << ptr1.use_count() << std::endl;
            std::cout << "ptr2 - " << ptr2->getValue() << ", count - " << ptr2.use_count() << std::endl;
            std::cout << "ptr3 - " << ptr3->getValue() << ", count - " << ptr3.use_count() << std::endl;
        }

        std::cout << "\nptr1 - can't dereferenced , count - " << ptr1.use_count() << std::endl;
        std::cout << "ptr2 - "   << ptr2->getValue() << ", count - " << ptr2.use_count() << std::endl;
    }
    
    std::cout << "\nptr1 - can't dereferenced , count - " << ptr1.use_count() << std::endl;
    std::cout << "ptr  - " << ptr->getValue()  << ", count - " << ptr.use_count()  << std::endl;

    return 0;
}

