// section challenge 4
// Identifying palindrome strings using a stack and queue

#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>

// check string is pallindrom or not
bool is_palindrome(const std::string &str) {
    std::stack<char> s;
    std::queue<char> q;

    // pushing alphabetic character to stack and queue
    for (auto ch: str) {
        if (isalnum(ch)) {
            s.push(::toupper(ch));
            q.push(::toupper(ch));
        }
    }

    // comparing top element of stack and front element of queue
    while (!s.empty()) {
        if (s.top() == q.front()) {
            s.pop();
            q.pop();
            continue;
        }
        return false;
    }
    return true;
}


int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
   
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    
    for(const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
    }
    std::cout << std::endl;
    
    return 0;
}