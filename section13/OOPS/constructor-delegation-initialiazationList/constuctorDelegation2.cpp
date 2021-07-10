// constuctor delegation

#include <iostream>
#include <string>

class Student {
// atributes
private:
    std::string name ;
    std::string course ;
    int age;

public:    
    Student();
    Student(std::string name);     
    Student(std::string name , std::string course);
    Student(std::string name , std::string course , int age); 

    ~Student();

// methods

};

//constuctor define
Student::Student () 
        : Student{"", "", 0} {
            std::cout << "No argument constuctor is called " << std::endl;
        }

Student::Student(std::string name) 
        : Student{name, "", 0} {
            std::cout << "single argument constuctor is called " << std::endl;
        }
Student::Student(std::string name, std::string course) 
        : name {name}, course {course} {
            std::cout << "double argument constuctor is called " << std::endl;
        }
Student::Student(std::string name, std::string course , int age) 
        : name {name}, course {course}, age {age} {
            std::cout << "all argument constuctor is called " << std::endl;
        }

// destuctor defination
Student::~Student() {
    std::cout << this->name << " destructor called" << std::endl;
}


int main() {
    Student frank;
    Student john("John", "CS");
    Student alice("Alice");
    Student kim ("kim", "Agreculture", 26);
//    Student ammy("ammy", 19);
    
    return 0;
}