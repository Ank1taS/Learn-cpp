// default constructor with default arguments

#include <iostream>
#include <string>

class Student {
// atributes
private:
    std::string name;
    std::string course;
    int age;

public:    
//    Student() {}

    // 1st initialised then assignment 
    Student(std::string name = "Nino", std::string course = "CS", int age = 20) {
        std::cout << "Default constuctor is called" << std::endl;
        this->name = name;
        this->course = course;
        this->age = age;
    }

// methods

};

int main() {
    Student frank;
    Student john;
    Student alice("Alice");
    
    return 0;
}