// to create class and its objects in varrious way
// 23.06.2021

//#include <iostream>
#include <string>
#include <vector>

class Student {

    // data members
    std::string name;
    std::string studentID {};
    size_t age {};

    // member function
    bool isPresent();
    double totalMark();
};

int main() {
    // creating obj of Student class
    Student Frank, Jonh, Aliy;

  //  Frank.name = "name"; // error
    // pointer to object
    Student *studentPtr1{};
    studentPtr1 = new Student();
    Student *studentPtr2 = new Student();

    delete studentPtr1;
    delete studentPtr2;

    // array of objects
    Student studentArr1[] {Frank, Jonh, Aliy};
    Student studentArr2[4];

    // vector objects of Student class
    std::vector<Student> studentVec1{Jonh};
    studentVec1.push_back(Frank);


    return 0;
}
