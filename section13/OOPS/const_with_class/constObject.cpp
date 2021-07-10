//! using const with classes

#include <iostream>

class Student {
    //atributes - private
public:
    std::string  name;
    std::string  course;
    size_t       age;

    //Default constuctor prototype
    Student(std::string name = "None", std::string course = "None", size_t age = 0);

    // destructor prototype
    ~Student();

    // methods 
    std::string getName() const;      // to get the name
    std::string setName();      // to modify the name

};

// default constructor definition - initialization list
Student::Student(std::string name, std::string course, size_t age)
       : name {name}, course {course}, age {age} {
}

// destructor definition
Student::~Student() {}

std::string Student::getName() const{
    return name;
}

std::string Student::setName() {
    name = "None";
}

// modify() definition - returns Student class object 
void displayName(const Student &objLocal) {
    std::cout << objLocal.getName() << std::endl;
}

int main() {
    Student john {"John", "Btech", 20};
    const Student Ammy {"Ammy", "CA", 18};

    john.getName();
    Ammy.getName();

    displayName(john);
    displayName(Ammy);

    return 0;
}
