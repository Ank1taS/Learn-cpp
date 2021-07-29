// Section 16
// Pure virtual functions and abstract base classes

#include <iostream>
#include <vector>

// Abstract Base class
class Shape {			
private:
       // attributes common to all shapes
public:
      virtual void draw() = 0;	        // pure virtual function
      virtual void rotate() = 0;        // pure virtual function
      virtual ~Shape() { }
};

// Abstract class
class Open_Shape: public Shape {    
public:
    // Derived abstract class can implement virtual method. If do then static binding occures
    // virtual void draw() override {
    //     std::cout << "OpenSource::Drawing a line" << std::endl;
    // }

    virtual ~Open_Shape() { }
};

// Abstract class
class Closed_Shape : public Shape {  
public:
    virtual ~Closed_Shape() { }
};

// Concrete class
class Line: public Open_Shape {     
public:
    virtual void draw() override {
        std::cout << "Drawing a line" << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotating a line" << std::endl;
    }
    virtual ~Line() {}
};

// Concrete class
class Circle: public Closed_Shape {     
public:
    virtual void draw() override {
        std::cout << "Drawing a circle" << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotating a circle" << std::endl;
    }
    virtual ~Circle() {}
};

// Concrete class
class Square: public Closed_Shape {     
public:
    virtual void draw() override {
        std::cout << "Drawing a square" << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotating a square" << std::endl;
    }
    virtual ~Square() {}
};


void screen_refresh(const std::vector<Shape *> &shapes) {
    std::cout << "\n===== Refreshing =====" << std::endl;
    for (const auto &p: shapes) 
        p->draw();
}

int main() {   
    // Shape s;
    // Shape *p = new Shape();

    // we cann't create object of an abstract class (containg implementation of overriden Functions(s)). 
    // we can only create objects of concrete(fully) containing implimemtation of all the virtual function of ingeritance hierarchies.
    // Shape *ptr = new Open_Shape();
    // ptr->draw();

    Shape *s1 = new Circle();
    Shape *s2 = new Line();
    Shape *s3 = new Square();
    
    std::vector<Shape *> shapes {s1,s2,s3};
    
    for (const auto &p: shapes) 
       p->draw();
        
    screen_refresh(shapes);
    
    delete s1;
    delete s2;
    delete s3;
    
    return 0;
}

