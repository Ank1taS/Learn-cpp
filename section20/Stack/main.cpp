// stack 

#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <list>

// This function displays a stack of by repeatedly topping and popping the stack Note theat the stack is passed in by value so we don't affect the passed in stack.
template <typename T1, typename T2>
void display(std::stack<T1, T2> sta) {
    std::cout << "[ ";

    while (!sta.empty()) {
        T1 element = sta.top();
        std::cout << element << " ";
        sta.pop();
    }
    std::cout << " ]" << std::endl;
}


// fot int stack
void display(std::stack<int> sta) {
    std::cout << "[ ";

    while (!sta.empty()) {
        int element = sta.top();
        std::cout << element << " ";
        sta.pop();
    }
    std::cout << " ]" << std::endl;
}

// stack of int
void intTest() {
    std::stack<int> s;

    for (int i: {1,2,3,4,5}) 
        s.push(i);
    display(s);

    s.push(100);
    display(s);
    
    s.pop();
    s.pop();
    display(s);
    
    while (!s.empty())
        s.pop();
    display(s);
    
    std::cout << "Size: " << s.size() << std::endl;
    
    s.push(10);
    display(s);
    
    s.top() = 100;
    display(s);

}

void vectorTest() {
    std::cout << "\n============================\n" << std::endl;

    std::stack<int, std::vector<int>> sv;

    for (int i: {1,2,3,4,5}) 
        sv.push(i);
    display(sv);

    sv.push(100);
    display(sv);
    
    sv.pop();
    sv.pop();
    display(sv);
    
    while (!sv.empty())
        sv.pop();
    display(sv);
    
    std::cout << "Size: " << sv.size() << std::endl;
    
    sv.push(10);
    display(sv);
    
    sv.top() = 100;
    display(sv);

}

int main() {
    intTest();
    vectorTest();

    return 0;
}

