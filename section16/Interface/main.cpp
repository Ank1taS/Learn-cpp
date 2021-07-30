// section 16
// abstract class as Interface

#include <iostream>
#include <vector>


// Interface - IPrintable
class IPrintable {
    friend std::ostream &operator<<(std::ostream &, const IPrintable &);

public:
    virtual void print(std::ostream &) const = 0;         // pure virtual method
    virtual ~IPrintable() {}
};

// Account - abstract class/ interface
class Account: public IPrintable {
public:
    virtual void print(std::ostream &) const = 0;         // pure virtual method
    virtual void withdraw(double) = 0;                          
    virtual void deposit(double) = 0;

    virtual ~Account() {}                                   // destructor           
};

// Saving Account - concrete class
class Savings: public Account {
public:
    virtual void print(std::ostream &os) const override{
        os << "Savings::print\n";
    }
    virtual void withdraw(double amount) override{
        std::cout << "Savings::withdraw" << std::endl;
    }
    virtual void deposit(double amount) override{
        std::cout << "Savings::deposit" << std::endl;
    }
    virtual ~Savings() {}
};

// Chaecking account - concrete class
class Checking: public Account {
public:
    virtual void print(std::ostream &os)const override{
        os << "Checking::print\n";
    }
    virtual void withdraw(double amount) override{
        std::cout << "Checking::withdraw" << std::endl;
    }
    virtual void deposit(double amount) override{
        std::cout << "Checking::deposit" << std::endl;
    }
    virtual ~Checking() {}
};

// Trust account - concrete class
class Trust: public Account {
public:
    virtual void print(std::ostream &os) const override{
        os << "Trust::print\n";
    }
    virtual void withdraw(double amount) override{
        std::cout << "Trust::withdraw" << std::endl;
    }
    virtual void deposit(double amount) override{
        std::cout << "Trust::deposit" << std::endl;
    }
    virtual ~Trust() {}
};

// overloaded Extraction operator
std::ostream &operator<<(std::ostream &os, const IPrintable &obj) {
    obj.print(os);          // calling derived classes print() according to obj 

    return os;
}

void displayVector(std::vector<Account *> &vec) {
    for (auto const &objPtr: vec) {
        std::cout << *objPtr << std::endl;
        objPtr->deposit(2000);
        objPtr->withdraw(1000);
    }
}

// main function
int main() {
    // Account obj1;        // can not create object of abstract class

    Savings  obj1;
    Checking obj2;
    Trust    obj3;

    std::cout << obj1 << obj2 << obj3 << std::endl; 

    std::cout << "----- Vector of Account class pointer -----" << std::endl;
    Account *p1 = new Savings();
    Account *p2 = new Checking();
    Account *p3 = new Trust();

    std::vector<Account *> accVec {p1, p3, p2};
    displayVector(accVec);
    
    // deleting pointer
    delete p1;
    delete p2;
    delete p3;

    return 0;
}