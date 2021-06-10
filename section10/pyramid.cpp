// Draw a pyramid of user's string 

#include <iostream>
#include <string>

int main() {
    std::string originalString;
    
    std::cout << "Enter the string: ";
    getline(std::cin, originalString);

    std::string tempString {originalString};
    size_t index {};

    // To remove white space
    while (true) {

        // index stores found possition of space
        index = tempString.find(" ");

        // checks if space is found or not
        if (index == std::string::npos) {
            break; // no space remain
        }

        // erase space from the index
        tempString.erase(index, 1);
    }

    // size stores tempstring length
    size_t size = tempString.length();

    //------------ Print pyramid -------------
    for(index = 0; index < size; ++index) {

        // to print space
        for (size_t sp {}; sp < size - index; ++sp) {
            std::cout << " ";
        }

        // print characters of string
        for (int count = 0; count < index; ++count) {
            std::cout << tempString.at(count);
        }

        // print reverse characters
        for (int count = index; count >= 0; --count) {
            std::cout << tempString.at(count);
        }

        std::cout << std::endl;
    } 

    return 0;
}
