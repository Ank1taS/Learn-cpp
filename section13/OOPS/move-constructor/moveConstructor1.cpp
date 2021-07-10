//! move copy constructor (vector of move class)

#include <iostream>
#include <vector>

// Move class
class Move {
private:
    //attributes
    int *data;

public:
    // Methords
    Move(int data = 10);        // default constructor
    Move(const Move &);         // copy constructor
    Move(Move &&) noexcept;     // move constructor 
    ~Move();                    // Destructor

    void setValue(int value) {      // modifies value that data pointer points
        *data = value;
    }

    int getValue() {                // returns value pointed by data
        return *data;
    }
};

// default constructor definition
Move::Move (int data) {
    this->data  = new int;
    *this->data = data;             // *(this->data) = data

    std::cout << "default counstructor for - " << *this->data << std::endl;
}

// copy(deep) constructor definition - delegation constructor
Move::Move (const Move &objSource) 
    : Move {*objSource.data} {
        std::cout << "Copy contructor (Deep copy) - " << *data << std::endl;
}

// Move constructor
Move::Move (Move &&source) noexcept
    : data {source.data} {
        source.data = nullptr;
        std::cout << "Move constructor - moving resource - " << *data << std::endl;
}

Move::~Move() {
    if (data != nullptr) {
        std::cout << "Destructor freeing data for " << *data << std::endl;
    }
    else {
        std::cout << "Destructor freeing data for nullptr..." << std::endl;
    }
    delete data;
}

int main() {
    std::vector<Move> vec;

    vec.push_back(Move{10});
    vec.push_back(Move{20});
    vec.push_back(Move{30});
    // vec.push_back(Move{40});
    // vec.push_back(Move{50});
    // vec.push_back(Move{60});
    // vec.push_back(Move{70});

    return 0;
}
