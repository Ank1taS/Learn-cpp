//! copy constuctor - delegating constructor
//! Default constuctor - initialization list
//! copy constructor possible occurance

#include <iostream>

class Student {
    //atributes - private
public:
    std::string  name;
    std::string  course;
    size_t       age;

    //Default constuctor prototype
    Student(std::string name = "None", std::string course = "None", size_t age = 0);

    //copy constuctor prototype
    Student(const Student &);

    // destructor prototype
    ~Student();

    // methods 
};

// default constructor definition - initialization list
Student::Student(std::string name, std::string course, size_t age)
        : name {name}, course {course}, age {age} {
        std::cout << "Default constuctor is called for - " << name << std::endl;
}

// copy constructor definition - delegating constructor
Student::Student(const Student &obj)
        : Student {obj.name, obj.course, obj.age} {
        std::cout << "Copy constuctor is called for - " << name << std::endl;
}

// destructor definition
Student::~Student() {
    std::cout << "Destructor is called for - " << name << std::endl;
}

// display() definition - paasing object as parameter
// but it can be better way by passing alias of object as parameter 
void display(Student objLocal) {
    std::cout << "======== Display " << objLocal.name << " ================" << std::endl;
    std::cout << "Name   - " << objLocal.name   << std::endl;
    std::cout << "course - " << objLocal.course << std::endl;
    std::cout << "age    - " << objLocal.age    << std::endl;
}

// modify() definition - returns Student class object 
Student modifitedObj(const Student &objLocal) {
    Student objcopy {objLocal};
    objcopy.course = "Law";
    objcopy.age = 30;

    return objcopy;
}

int main() {
    Student john;
    Student ammy  {"Ammy"};
    Student frank {"Frank"  ,   "Agreculture"};
    Student jack  {"Lee Jackson", "CS", 23};

    // copying object
    Student jackCopy {jack};

    // display() - passing object as parameter
    display(jack);

    // modify - returns Student class object 
    ammy = modifitedObj(ammy);
    display(ammy);

    return 0;
}
