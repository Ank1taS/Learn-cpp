// Function Template

#include <iostream>
#include <string>

class Person {
private:
    // friend function
    friend std::ostream &operator<<(std::ostream &, const Person&);

    // attribute
    std::string name;
    int age; 

public:
    // default constructor
    Person(std::string name, int age)
        : name {name}, age {age} {} 

    // Destructor
    ~Person() {}

    // overloaded < operator
    bool operator>(const Person &rhs) const {
        return this->age > rhs.age;
    }

};

// overloaded << operator 
std::ostream &operator<<(std::ostream &os, const Person &rhs) {
    os << rhs.name << " : " << rhs.age;
    
    return os;
}

// display function
template <typename T1, typename T2>
void display(T1 obj1, T2 obj2) {
    std::cout << obj1 << "\t" << obj2 << std::endl; 
}

// to find maximum
template <typename T>
T max(T obj1, T obj2) {
    return (obj1 > obj2) ? obj1 : obj2; 
}

int main() {
    int x1{10};
    int y1{20};

    display(x1, y1);                                    // 10   20
    std::cout << "greater is " << max(x1, y1) << std::endl;;

    float x2{10.5};
    float y2{20.8};

    display(x2, y2);                                    // 10   20        ok! - can be of same typr
    std::cout << "greater is " << max(x2, y2) << std::endl;

    int x3{10};
    float y3{20};

    display(x3, y3);                                    // 10   20        ok! - can be of different type
 //   std::cout << "greater is " << max(x3, y3);        //max() expects arguments of similar type

    std::cout << max<float>(7.9999, 8.0) << std::endl;
    std::cout << max(7.9999, 8.0) << std::endl;         // compiler can deduce the type
    std::cout << max(20, 30) << std::endl;
    std::cout << max("Ankita", "ankita") << std::endl;
    std::cout << max((30 / 0.5 + 10), (30 *0.5 + 10)) << std::endl;
    
    Person frank {"Frank", 30};
    Person ammy {"ammy", 28};
  //  Person p = max(frank, ammy);

    std::cout << "Older is " << max(frank, ammy) << std::endl;

    display(frank, ammy);
    display("Hello", "World...");
    display(std::string{"Hello"}, frank);
    display("Hello", ammy);
    display<char, int>('a', 97);
    display('a', 97);                                   // compiler can deduce the type

    return 0;
}
