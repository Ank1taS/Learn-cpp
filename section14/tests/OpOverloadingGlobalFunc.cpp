//?  overloading operator as global function
//?  checking if the global function can access private attribute of a class while being a non-frind funcion 
//?  It can't. 1 - Either the global function needs to be friend of the class or class or 
//?            2 - It needs to access private though a getter methord of the class


#include <iostream>



// class definition
class MyClassTest {
    //attribute
    int val1;
    float val2;

public:
    MyClassTest(int val1 = 0, float val2 = 0.0);         // default constructor
    ~MyClassTest();                                     // destructor
    friend bool operator==(MyClassTest sourceObj1, MyClassTest sourceObj2);    // global() as friend
};

// global function
bool operator==(MyClassTest sourceObj1, MyClassTest sourceObj2) {
    if (sourceObj1.val1 == sourceObj2.val1 && sourceObj1.val2 == sourceObj2.val2) {
        return true;
    }
    return false;
}

MyClassTest::MyClassTest(int val1, float val2) {
    this->val1 = val1;
    this->val2 = val2;
}

MyClassTest::~MyClassTest() {}

int main() {
    MyClassTest obj1(2);
    MyClassTest obj2(10, 10.5);

    if (obj1 == obj2) {
        std::cout << "obj1 == obj2" << std::endl;  
    }
    else {
        std::cout << "obj1 != obj2" << std::endl;  
    }
    return 0;
}
