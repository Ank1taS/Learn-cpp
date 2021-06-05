// vector operation as instructed

#include <iostream>
#include <vector>

int main() {
    // declare 2 empty integer vector
    std::vector<int> vec1,vec2;

    //adding 10, 20 to vec1 and display element and size
    vec1.push_back(10);
    vec1.push_back(20);

    std::cout << "Elements of vector1 - ";
    std::cout << vec1.at(0) << "\t" << vec1.at(1) << std::endl;
    std::cout << "Size of vector1 - " << vec1.size() << std::endl;

    //adding 100, 200 to vec2 and display element and size
    vec2.push_back(100);
    vec2.push_back(200);

    std::cout << "Elements of vector2 - ";
    std::cout << vec2.at(0) << "\t" << vec2.at(1) << std::endl;
    std::cout << "Size of vector2 - " << vec2.size() << std::endl;

    //declaring 2d vector
    std::vector<std::vector<int>> vector2D;
    
    //adding vec1, vec2 to 2DVector and display element of 2DVector
    vector2D.push_back(vec1);
    vector2D.push_back(vec2);

    std::cout << "Elements of vector2D - \n";
    std::cout << vector2D.at(0).at(0) << "\t" << vector2D.at(0).at(1) << std::endl;
    std::cout << vector2D.at(1).at(0) << "\t" << vector2D.at(1).at(1) << std::endl;

    //change vec1[0] to 1000
    vec1.at(0) = 1000;

    //display elements of vec1
    std::cout << "Elements of vector1 - ";
    std::cout << vec1.at(0) << "\t" << vec1.at(1) << std::endl;

    //display elements of vector2D
    std::cout << "Elements of vector2D - \n";
    std::cout << vector2D.at(0).at(0) << "\t" << vector2D.at(0).at(1) << std::endl;
    std::cout << vector2D.at(1).at(0) << "\t" << vector2D.at(1).at(1) << std::endl;

    // vector2D does not change as vector2D.at(0) and vec1.at(0) are 2 different memory address

    return 0;
}