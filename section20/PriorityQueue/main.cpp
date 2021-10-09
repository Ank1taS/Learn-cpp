// Priority Queue

#include <iostream>
#include <queue>

class Person {
    friend std::ostream &operator<<(std::ostream &os, const Person &p);

    std::string name;
    int age;

public:
    Person(std::string name = "Unknown", int age = 0) 
        : name{name}, age{age}  {}

    bool operator<(const Person &rhs) const {
        // return this->age < rhs.age;
        return this->name < rhs.name;
    }

    bool operator==(const Person &rhs) const {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

std::ostream &operator<<(std::ostream &os, const Person &p) {
    os << p.name << ":" << p.age;
    return os;
}

// This displays the priority queue by repeatedly topping and popping the priority queue
// It is being passed by value so we don't modify the priority queue being passed in
template <typename T>
void display(std::priority_queue<T> pq)  {
    std::cout << "[ ";

    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout <<  "]" << std::endl;
}

void  test1() {
    std::cout << "\n======== Test1 =========" << std::endl;

    std::priority_queue<int> pq;

    for (int i : {3,5,7,12,23,12,4,100,0, 3,5,7})
        pq.push(i);
        
    std::cout << "Size: " << pq.size() << std::endl;
    std::cout << "Top: " << pq.top() << std::endl;
        
    display(pq);
    
    pq.pop();
    display(pq);
}

void test2() {
    std::cout << "\n======== Test2 =========" << std::endl;

    std::priority_queue<Person> pq;
    pq.push(Person{"Ammy", 10});
    pq.push(Person{"Brick", 1});
    pq.push(Person{"Chang", 14});
    pq.push(Person{"Franky", 18});  
    pq.push(Person{"Edward", 7});  
    pq.push(Person{"Frank", 27});
    
    display(pq);
}

int main() {
    test1();
    test2();

    return 0;
}

