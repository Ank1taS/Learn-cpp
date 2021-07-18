//todo      Section 14
//todo      Challenge - Solution 1 - main.cpp
//Todo      Member methods

#include "header.h"

using namespace std;

int main() {
    
    cout << boolalpha << endl;
    MyString a {"frank"};
    MyString b {"frank"};
    cout << (a==b) << endl;              // true
    cout << (a!=b) << endl;              // false
    
    b = "george";
    cout << (a==b) << endl;              // false
    cout << (a!=b) << endl;              // true
    cout << (a<b) << endl;               // true
    cout << (a>b) << endl;               // false
    
    MyString s1 {"FRANK"};

   cout << s1 << endl;                   // FRANK              
    s1 = -s1;       
    cout << s1 << endl;                  // frank              

    s1 = s1 + "*****";
    cout << s1 << endl;                  // frank*****       
    
    s1 += "-----";                       // frank*****-----
    cout << s1 << endl;
    
    MyString s2{"12345"};
    s1 = s2 * 3;
    cout << s1 << endl;                  // 123451234512345
    
    MyString s3{"abcdef"};  
    s3 *= 5;
    cout << s3 << endl;                  // abcdefabcdefabcdefabcdefabcdef
    
    MyString repeat_string;
    int repeat_times;
    cout << "Enter a string to repeat: " << endl;
    cin >> repeat_string;
    cout << "How many times would you like it repeated? " << endl;
    cin >> repeat_times;
    repeat_string *= repeat_times;
    cout << "The resulting string is: " << repeat_string << endl;
    
    cout << (repeat_string * 12) << endl;
    
    repeat_string = "RepeatMe";
    // cout << (repeat_string + repeat_string + repeat_string) << endl;
    
    repeat_string += (repeat_string * 3);
    cout << repeat_string << endl;
    
    repeat_string = "RepeatMe";
    repeat_string += (repeat_string + repeat_string + repeat_string);


    MyString s = "Frank";
    ++s;
    cout << s << endl;                   // FRANK
    
    s = -s; 
    cout << s << endl;                   // frank
    MyString result;
    result = ++s;                           
    cout << s << endl;                   // FRANK
    cout << result << endl;              // FRANK
    
    s = "Frank";
    s++;
    cout << s << endl;                   // FRANK
    
    s = -s;
    cout << s << endl;                   // frank
    result = s++;
    cout << s << endl;                   // FRANK
    cout << result << endl;              // frank
    return 0;
}

