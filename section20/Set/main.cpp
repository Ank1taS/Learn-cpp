// set

#include <iostream>
#include <set>

class Person {
    friend std::ostream &operator<<(std::ostream &, const Person &);

    // attribute
    std::string name;
    int age;
    
public:
    // constructor
    Person (std::string name = "Unknown", int age = 0) 
        : name {name}, age {age} {}
    
    // destructor
    ~Person() = default;

    // overloaded < operator
    bool operator<(const Person &rhs) const {
        // return (this->age < rhs.age);
        return (this->name < rhs.name);
    }

    // overloaded == operator
    bool operator==(const Person &rhs) const {
        return (this->age == rhs.age) && (this->name == rhs.name);
    }

    // getters
    std::string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

};

// overloaded << operator
std::ostream &operator<<(std::ostream &os, const Person &obj) {
    os << obj.getName() << " : " << obj.getAge();
    return os;
}

// display 
template <typename T>
void display(const std::set<T> &obj) {
    std::cout << "[  ";
    
    for (const auto &element : obj) {
        std::cout << element << "  ";
    }

    std::cout << " ]" << std::endl;
}

void test1() {
    std::cout << "\n=======Test1=======\n" << std::endl;

    std::set<int> set1 {1, 5, 8};
    display(set1);

    set1 = {1, 6, 9, 5, 6, 6, 3, 2};
    display(set1);

    // insert() - insert element in order
    set1.insert(0);
    set1.insert(7);
    display(set1);

    // count() - to test presence of an elemant
    if (set1.count(7)) {
        std::cout << "Found 7..." << std::endl;
    }
    else {
        std::cout << "Not found 7..." << std::endl;
    }

    if (set1.count(10)) {
        std::cout << "Found 10..." << std::endl;
    }
    else {
        std::cout << "Not found 10..." << std::endl;
    }

    // find() - to find specific elemnt in the set
    auto it = set1.find(6);
    if (it != std::end(set1)) {
        std::cout << "Found " << *it << std::endl;
    }

    it = set1.find(4);
    if (it != std::end(set1)) {
        std::cout << "Found " << *it << std::endl;
    }

    // clear() = to delete set element
    set1.clear();
    display(set1);
}

void test2() {
    std::cout << "\n========Test2=======\n" << std::endl;

    std::set<Person> p {{"Frank", 48}};    
    display(p);                             // order of display!  operator<

    p.insert({"Ammy", 30});
    display(p);

    p.emplace("Jack", 25);
    display(p);

    // p.emplace("Frank", 50);              // No - Frank already exists   
    // display(p);
    
    auto result = p.emplace("Frank", 50);   // No - Frank already exists
    display(p);

    std::cout << std::boolalpha;
    std::cout << "Frist : " << *(result.first) << std::endl;
    std::cout << "Second: " << result.second << std::endl;

    p.emplace("Kim hung", 30);              // ok
    display(p);

    auto it = p.find(Person{"Ammy", 30});
    
    if (it != p.end()) {
        p.erase(it);
    } 
    display(p);

    it = p.find(Person("Tae", 25));         // will remove [jack, 25] if arranged by age

    if (it != p.end()) {
        p.erase(it);
    } 
    display(p);
}

void test3() {
    std::cout << "\n=======Test3======\n" << std::endl;

    std::set<std::string> str {"A", "N", "K", "I", "T", "A"};
    display(str);

    auto result = str.insert("S");
    display(str);

    std::cout << std::boolalpha;
    std::cout << "Frist : " << *(result.first) << std::endl;
    std::cout << "Second: " << result.second << std::endl;

    result = str.insert("N");
    display(str);

    std::cout << "Frist : " << *(result.first) << std::endl;
    std::cout << "Second: " << result.second << std::endl;
}

int main() {
    test1();
    test2();
    test3();

    return 0;
}
