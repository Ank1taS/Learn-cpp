// Section 14
// Overloading move constructor and move assignment operator
#include <iostream>
#include <vector>
#include "header.h"

using namespace std;

int main() {
    
    MoveMyString a{"Hello"};                // Overloaded constructor
    a = MoveMyString{"Hola"};              // Overloaded constructor then move assignment
    a = "Bonjour";                         // Overloaded constructor then move assignment
    //* here "Bonjour" is a c-style string one right hand side but we have a MoveMyString class constructor
    //* that can construct MoveMyString class object from c-stylr string 
 
    MoveMyString empty;                      // no-args constructor
    MoveMyString larry("Larry");             // overloaded constructor
    MoveMyString stooge {larry};            // copy constructor 
    MoveMyString stooges;                   // no-args constructor
    
    empty = stooge;                     // copy assignment operator
                                                  // stooge is an l-value
    
    empty = "Funny";                    // move assignment operator
                                                  // "Funny" is an r-value
    
    empty.display();
    larry.display();
    stooge.display();
    empty.display();
    
    stooges = "Larry, Moe, and Curly";  
    stooges.display();
    
    vector<MoveMyString> stooges_vec;
    stooges_vec.push_back("Larry");                // Move constructor
    stooges_vec.push_back("Moe");                // Move constructor
    stooges_vec.push_back("Curly");              // Move constructor    
    
    cout << "=== Loop 1 ==================" << endl;
    for (const MoveMyString &s: stooges_vec) 
        s.display();
        
    cout << "=== Loop 2 ==================" << endl;
    for (MoveMyString &s: stooges_vec)
        s = "Changed";                                      // move assignment
        
    cout << "=== Loop 3 ==================" << endl;
    for (const MoveMyString &s: stooges_vec) 
        s.display();
        
    
    return 0;
}

