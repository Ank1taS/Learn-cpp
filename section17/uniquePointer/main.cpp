//* Unique pointer


#include <iostream>
#include <vector>
#include <memory>

class UniquePointerClass {
    // atribute
    int value;

public:
    // default constructor
    UniquePointerClass(int value = 0)
        : value {value} {
        std::cout << "constructor : " << value << std::endl;
    } 

    // destructor
    ~UniquePointerClass() {
        std::cout << "destructor  : " << value << std::endl;
    }

    // getter
    int getValue() const {
        return value;
    }
};


int main() {

    std::unique_ptr<UniquePointerClass> ptr1 {new UniquePointerClass{100}};                     // way - 01
    std::unique_ptr<UniquePointerClass> ptr2 = std::make_unique<UniquePointerClass> (200);      // way - 02
    auto ptr3 = std::make_unique<UniquePointerClass>(300);                                      // way - 03
  //  auto ptr3 {new UniquePointerClass{300}};                                                    
    
    std::vector<std::unique_ptr<UniquePointerClass>> vec ;
    vec.push_back(std::move(ptr1));
    vec.push_back(std::move(ptr2));
    vec.push_back(std::move(ptr3));


    for (const auto &obj : vec) {
        std::cout << "value - " << obj->getValue() << std::endl;
    }

    return 0;
}
