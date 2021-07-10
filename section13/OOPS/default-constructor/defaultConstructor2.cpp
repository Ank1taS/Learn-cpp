// default initialisation list constructor with default arguments

#include <iostream>
#include <string>

class Student {
// atributes
private:
    std::string name;
    std::string course;
    int age;

public:    
    Student(std::string name = "Nino", std::string course = "CS", int age = 20);      
    ~Student();
// methods

};

// constuctor definition
Student::Student(std::string name, std::string course, int age)
    : name {name}, course {course}, age {age} {
        std::cout << "constuctor with default argument is called for " << this->name << std::endl;
    }

// destroctor definition
Student::~Student() {
    std::cout << "destructor with default argument is called for " << this->name << std::endl;
}

int main() {
    Student frank;
    Student john("Jhon", "Agreculture");
    Student alice("Alice");
    Student ammy ("Ammy", "BBA", 18);
    
    return 0;
}