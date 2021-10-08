// queue

#include <iostream>
#include <queue>
#include <list>

// This function displays a queue of by repeatedly removing elements from the front.
// Note theat the queue is passed in by value so we don't affect the passed in queue.

// for queue with default underline container deque 
template<typename T>
void display(std::queue<T> q) {
    std::cout << "[ ";

    while (! q.empty()) {
        T element = q.front();
        std::cout << element << " ";
        q.pop();
    }

    std::cout << " ]" << std::endl;
}

// // for queue with any underline container
template<typename T1, typename T2>
void display(std::queue<T1, T2> q) {
    std::cout << "[ ";

    while (! q.empty()) {
        T1 element = q.front();
        std::cout << element << " ";
        q.pop();
    }

    std::cout << " ]" << std::endl;
}

void queue() {
    // default implemented container is deque
    std::queue<int> q;
    
    for (int i: {1,2,3,4,5}) 
        q.push(i);
    display(q);
    
    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back:  " << q.back() << std::endl;

    q.push(100);
    display(q);

    q.pop();
    q.pop();
    display(q);
    
    while (!q.empty())
        q.pop();
    display(q);

    std::cout << "Size: " << q.size() << std::endl;
    
    q.push(10);
    q.push(100);
    q.push(1000);
    display(q);
    
    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back:  " << q.back() << std::endl;
    
    q.front() = 5;
    q.back() = 5000;
    
    display(q);
    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back:  " << q.back() << std::endl;
}

void listQueue() {
    std::cout << "\n===========================\n" << std::endl;

    std::queue<int, std::list<int>> q;

    for (int i: {1,2,3,4,5}) 
        q.push(i);
    display(q);
    
    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back:  " << q.back() << std::endl;

    q.push(100);
    display(q);

    q.pop();
    q.pop();
    display(q);
    
    while (!q.empty())
        q.pop();
    display(q);

    std::cout << "Size: " << q.size() << std::endl;
    
    q.push(10);
    q.push(100);
    q.push(1000);
    display(q);
    
    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back:  " << q.back() << std::endl;
    
    q.front() = 5;
    q.back() = 5000;
    
    display(q);
    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back:  " << q.back() << std::endl;
}

int main() {
    queue();
    listQueue();

    return 0;
}