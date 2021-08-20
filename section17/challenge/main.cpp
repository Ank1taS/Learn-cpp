//* Section challenge 17

#include <iostream>
#include <vector>
#include <memory>

class Test {
private:
    // attributes
    int data;
public:
    // defult constructor
    Test(int data = 0) 
        : data{data} { 
        std::cout << "Test class constructor called for " << data << std::endl; 
    }

    // getter
    int get_data() const {
        return data; 
    }

    // destructor
    ~Test() {
        std::cout << "Test class destructor called for " << data << std::endl; 
    }
};

// make() definition 
// creates and returns a unique_ptr to a vector of shared_ptrs to Test objects. 
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make() {
    return std::make_unique<std::vector<std::shared_ptr<Test>>> ();
}

// fill() definition
// expects a vector of shared pointers to Test objects and a int representing the number of Test objects to create dynamically and add to the vector.
// fill() will prompt the user to enter an integer, create a shared_ptr to a Test object initialized to the entered integer and add that shared pointer to the vector. 
void fill(std::vector<std::shared_ptr<Test>> &vec, int num) {
    int dataValue;       

    for(int i {0}; i < num; ++i) {
        std::cout << "Enter data for Test [0] - ";
        std::cin  >> dataValue;

        // std::shared_ptr<Test> sharePtr = std::make_shared<Test> (dataValue);
        // vec.push_back(sharePtr);

       vec.push_back(std::make_shared<Test> (dataValue));
    }
}

// display() definition
// expects a vector of shared_ptrs to Test object and displays the data in each Test object
void display(const std::vector<std::shared_ptr<Test>>&vec) {
    std::cout << "============================" << std::endl;
    std::cout << "Vector Elements" << std::endl;

    for (auto const &ptr : vec) {
        std::cout << ptr->get_data() << std::endl;
    }
    std::cout << "============================" << std::endl;
}

int main() {
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vecPtr;
    vecPtr = make();
 
    std::cout << "How many data points do you want to enter: ";
    int num;
    std::cin >> num;
 
    fill(*vecPtr, num);
    display(*vecPtr);
 
    return 0;
}
