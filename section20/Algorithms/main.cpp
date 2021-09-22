// stl Algorithms

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
// #include <cctype>

// Person class
class Person {
private:
    // attributes
    std::string name;
    int age;

    // operator << overloaded Function
    friend std::ostream &operator<<(std::ostream &os, const Person &rhs) {
        os << rhs.name << " : " << rhs.age << std::endl;

        return os;
    }

public:
    // default constructor
    Person (std::string name = "None", int age = 0)
        : name {name}, age {age} {};

    // overloaded == operator
    bool operator==(const Person &rhs) const {
        return (this->age == rhs.age && this->name == rhs.name);
    }

    // getter - name
    std::string getName() const {
        return name;
    } 

    // getter - age
    int getAge() const {
        return age;
    }

    // setter - age
    void setAge() {
        age = 30;
    }
};

// find a specific element in the container - std::find()
void findElement() {
    std::cout << "\n=========================================" << std::endl;

    // vector of integers
    std::vector<int> vec1 {10, 5, 10, 20};

    auto loc1 = std::find(std::begin(vec1), std::end(vec1), 10);                            // found
    // auto loc1 = std::find(std::begin(vec1), std::end(vec1), 50);                         // not found

    if (loc1 != std::end(vec1)) {
        std::cout << "Found the element " << *loc1 << std::endl;
    }
    else {
        std::cout << "Can not found the element " << std::endl;
    }

    // Person object
    Person p1 {"Frank", 40};
    Person p2 {"Ammy", 25};
    Person p3 {"Jhon", 30};
    Person p4 {"Daniel", 48};

    // using container vector 
    std::vector<Person> vec2 {p1, p2, p3, p4, Person{"Petter", 45}};

    // auto loc2 = std::find(std::begin(vec2), std::end(vec2), p2);                         // found
    // auto loc2 = std::find(std::begin(vec2), std::end(vec2), Person{"Ammy", 25});         // found
    auto loc2 = std::find(std::begin(vec2), std::end(vec2), Person{"Petter", 45});          // found
    // auto loc2 = std::find(std::begin(vec2), std::end(vec2), Person{"Kim", 30});          // not found

    if (loc2 != std::end(vec2)) {
        std::cout << "Found the element " << *loc2 << std::endl;
    }
    else {
        std::cout << "Can not found the element " << std::endl;
    }

    // using container list
    std::list<Person> plist1 {p1, p2, p3, p4, {"Petter", 45}};

    // auto loc3 = std::find(std::begin(plist1), std::end(plist1), p3);                     // found
    auto loc3 = std::find(std::begin(plist1), std::end(plist1), Person{"Petter", 45});      // found
    // auto loc3 = std::find(std::begin(plist1), std::end(plist1), Person{"kim", 30});      // not found

    if (loc3 != std::end(plist1)) {
        std::cout << "Found the element " << *loc3 << std::endl;
    }
    else {
        std::cout << "Can not found the element " << std::endl;
    }

    std::list<Person> plist2 {
        {"Frank", 20},
        {"Ammy", 25},
        {"Jhon", 30}
    };

    // auto loc4 = std::find(std::begin(plist2), std::end(plist2), Person{"Petter", 45});   // not found
    auto loc4 = std::find(std::begin(plist2), std::end(plist2), Person{"Ammy", 45});        // not found 
    // auto loc4 = std::find(std::begin(plist2), std::end(plist2), Person{"Ammy", 25});     // found

    if (loc4 != std::end(plist2)) {
        std::cout << "Found the element " << *loc4 << std::endl;
    }
    else {
        std::cout << "Can not found the element " << std::endl;
    }
}

// count the number of occurrences of an element in a given range of a container
void countAllElement() {
    std::cout << "\n==========================================" << std::endl;

    // vector of integers
    std::vector<int> vec1 {10, 5, 10, 20};

    int totalElementCount1 = std::count(std::begin(vec1), std::end(vec1), 10);
    std::cout << "Elements found " << totalElementCount1 << " times." << std::endl;
    
    totalElementCount1 = std::count(std::begin(vec1), std::end(vec1), 1);
    std::cout << "Elements found " << totalElementCount1 << " times." << std::endl;

    // Person object
    Person p1 {"Frank", 40};
    Person p2 {"Ammy", 25};
    Person p3 {"Jhon", 30};
    Person p4 {"Daniel", 48};

    // using container vector 
    std::vector<Person> vec2 {p1, p2, p3, p4, Person{"Petter", 45}};

    int totalElementCount2 = std::count(std::begin(vec2), std::end(vec2), Person{"Ammy", 55});
    std::cout << "Elements found " << totalElementCount2 << " times." << std::endl;

    totalElementCount2 = std::count(std::begin(vec2), std::end(vec2), Person{"Ammy", 25});
    std::cout << "Elements found " << totalElementCount2 << " times." << std::endl;

    vec2.push_back(Person{"Ammy", 25});
    totalElementCount2 = std::count(std::begin(vec2), std::end(vec2), Person{"Ammy", 25});
    std::cout << "Elements found " << totalElementCount2 << " times." << std::endl;
}

// count the number of elements in a given range of a container, sartisfing a condition  
void countSpecificElement() {
    std::cout << "\n=========================================" << std::endl;

    std::vector<int> vec1 {10, 50, 20, 5, 10, 25, 5};

    // to count even elements - using lambda expression
    int evenCount = std::count_if(std::begin(vec1), std::end(vec1), [] (int x) {return x % 2 == 0;}); 
    std::cout << "Total even elements - " << evenCount << std::endl;

    // to count odd elements - using lambda expression
    int oddCount = std::count_if(std::begin(vec1), std::end(vec1), [] (int x) {return x % 2 != 0;}); 
    std::cout << "Total odd elements  - " << oddCount << std::endl;

    // Person object
    Person p1 {"Frank", 40};
    Person p2 {"Ammy", 25};
    Person p3 {"Jhon", 30};
    Person p4 {"Daniel", 48};

    // using container vector 
    std::vector<Person> vec2 {p1, p2, p3, p4, Person{"Petter", 45}};

    // to count person in vec2 vector, more than equal 40 years
    int count40 = std::count_if(std::begin(vec2), std::end(vec2), [] (Person p) {return p.getAge() >= 40;}); 
    std::cout << "Persons more than 40 - " << count40 << std::endl;
}

// To replace all occurance of a specific element
void replaceElement() {
    std::cout << "\n=========================================" << std::endl;

    std::vector<int> vec1 {10, 15, 20, 20, 38, 20, 50};

    // displaying elements
    std::cout << "[ ";
    for (auto &num : vec1) {
        std::cout << num << " ";
    }
    std::cout << " ]" << std::endl;

    std::replace(std::begin(vec1), std::end(vec1), 20, 100);

    // displaying elements
    std::cout << "[ ";
    for (auto &num : vec1) {
        std::cout << num << " ";
    }
    std::cout << " ]" << std::endl;

    // Person object
    Person p1 {"Frank", 40};
    Person p2 {"Ammy", 25};
    Person p3 {"Jhon", 30};
    Person p4 {"Daniel", 48};

    // using container vector 
    std::vector<Person> vec2 {p1, p2, p3, p4, Person{"Petter", 45}};

    // display 
    std::cout << "[ ";
    for (auto &person : vec2) {
        std::cout << person;
    }
    std::cout << " ]" << std::endl;

    std::replace(std::begin(vec2), std::end(vec2), Person{"Ammy", 25}, Person{"Ammy", 28});

    // display 
    std::cout << "[ ";
    for (auto &person : vec2) {
        std::cout << person;
    }
    std::cout << " ]" << std::endl;

}

// to check a condition is true or false for all the element of containers
void testAllElement() {
    std::cout << "\n=========================================" << std::endl;

    std::vector<int> vec1 {10, 15, 20, 20, 38, 20, 50};

    // to test all elements are divisible by 5 or not
    if (std::all_of(std::begin(vec1), std::end(vec1), [] (int num) {return num % 5 == 0;})) {
        std::cout << "All the elements are divisible by 5" << std::endl;
    }
    else {
        std::cout << "All the elements are not divisible by 5" << std::endl;
    }

    // Person object
    Person p1 {"Frank", 40};
    Person p2 {"Ammy", 25};
    Person p3 {"Jhon", 30};
    Person p4 {"Daniel", 48};

    // using container vector 
    std::vector<Person> vec2 {p1, p2, p3, p4, Person{"Petter", 45}};

    // to test all person objects are above 20 or not
    if (std::all_of(std::begin(vec2), std::end(vec2), [] (Person p) {return p.getAge() > 20;})) {
        std::cout << "All persons are above 20. " << std::endl;
    }
    else {
        std::cout << "Not all persons are above 20. " << std::endl;
    }
}

// to transform all the elements of a container
void transformElement() {
    std::cout << "\n=========================================" << std::endl;

    // container - vector
    std::vector<int> vec1 {10, 15, 20, 20, 38, 20, 50, 10, 10, 10};

    // displaying elements
    std::cout << "[ ";
    for (auto &num : vec1) {
        std::cout << num << " ";
    }
    std::cout << " ]" << std::endl;

    // std::transform(std::begin(vec1), std::end(vec1), std::begin(vec1), [] (int num) {return num + 10;});
    
    // 3rd argument is the start index to store result
    // vector - vec1 is updated after each n every trasformation of a index . so here 0th index updated value stored at 
    // 2nd index and for 2nd index, transformation will be done over the already updated value. 
    std::transform(std::begin(vec1), std::end(vec1), std::begin(vec1) + 2, [] (int num) {return num + 10;});

    // displaying elements
    std::cout << "[ ";
    for (auto &num : vec1) {
        std::cout << num << " ";
    }
    std::cout << " ]" << std::endl;

    // container - string
    std::string str {"Hello world"};
    std::cout << str << std::endl;

    // str will be transformed to upper case
    std::transform(std::begin(str), std::end(str), std::begin(str), ::toupper);
    std::cout << str << std::endl;
}

int main() {
    findElement();
    countAllElement();
    countSpecificElement();
    replaceElement();
    testAllElement();
    transformElement();
}
