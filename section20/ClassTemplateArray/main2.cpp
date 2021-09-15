// class template - Array

#include <iostream>
#include <string>

// class person
class Person {
private:
    // overloaded << operator overloaded friend function
    friend std::ostream &operator<<(std::ostream &os, const Person &obj) {
        os << obj.name << " - " << obj.age;

        return os;
    } 

    std::string name;
    int age;

public:
    // default constructor
    Person(std::string name = "name", int age = 0) 
        : name {name}, age {age} {}

    // destructor
    ~Person() = default;

};


// Array template
template <typename T, size_t N>
class Array {
private:

    //int size {size};
    T arrayName[N];

    // friend function
    friend std::ostream &operator<<(std::ostream &os, const Array<T, N> &arr) {
        os << "[ ";

        for (const auto &val: arr.arrayName) {
            os << val << " ";
        }

        os << " ]" << std::endl;

        return os;
    }
public:
    // default constructor
    Array() = default;

    // parameterised constructor
    Array(T initialValue) {
        for (auto &item: arrayName) {
            item = initialValue;
        }
    }

    // setter
    void fillArray(T newValue) {
        for (auto &existingItem: arrayName) {
            existingItem = newValue;
        }
    }

    // getter - size
    size_t getSize() {
        return N;
    }

    // subscript operator [] overloaded function
    T &operator[](int index) {
        return arrayName[index];
    }
};

int main() {
        
    Array<int, 5> nums;
    std::cout << "The size of nums is: "<< nums.getSize() << std::endl;
    std::cout << nums << std::endl;
    
    nums.fillArray(0);
    std::cout << "The size of nums is: "<< nums.getSize() << std::endl;
    std::cout << nums << std::endl;
    
    nums.fillArray(10);
    std::cout << nums << std::endl;

    nums[0] = 1000;
    nums[3] = 2000;
    std::cout << nums << std::endl;
    
    Array<int, 50> nums2 {1};
    std::cout << "The size of nums2 is: "<< nums2.getSize() << std::endl;
    std::cout << nums2 << std::endl;

    Array<std::string, 10> strings(std::string{"Frank"});
    std::cout << "The size of strings is: "<< strings.getSize() << std::endl;
    std::cout << strings << std::endl;
    
    strings[0] = std::string{"Larry"};
    std::cout << strings << std::endl;
    
    strings.fillArray(std::string{"Ammy"});
    std::cout << strings << std::endl;


    Person p1 {"Edwick", 38};
    Person p2 {"Jhon", 20};
    Person p3 {"Peter", 25};
    Person p4 {"Ammy", 22};

    Array<Person, 2> personArray1 {};
    Array<Person, 5> personArray2 {p1};

    std::cout << personArray1 << std::endl;
    std::cout << personArray2 << std::endl;

    personArray1.fillArray(p1);
    personArray2[1] = p2;
    personArray2[2] = p3;
    personArray2[3] = p4;
    personArray2[4] = p2;

    std::cout << personArray1 << std::endl;
    std::cout << personArray2 << std::endl;

    return 0;
}

