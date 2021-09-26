// Challenge 1
// Identifying palindrome strings using a deque

// #include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

bool is_palindrome(const std::string& s)
{
    // You must implement this function.
    // Since we are learning the STL - use a deque to solve the problem.

    std::deque<char> dec1;
    std::deque<char> dec2;

    for (auto ch : s) {
        if (isalpha(ch)) {
            dec1.push_back(::toupper(ch));
        }
    }

    // copying deque d1 element to d2 in reverse order
    std::copy(std::begin(dec1), std::end(dec1), std::front_inserter(dec2));

    // comparing both deque
    if (dec1 == dec2) {
        return true;
    }

    return false;
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