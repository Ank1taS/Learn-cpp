// multiply elements of 2 array and store in 3rd dynamically ctered array
// as instucted in section 12 challenge

#include "header.h"
//#include <iostream>

int main() {
    // size of array1
    size_t arr1Size {};
    
    std::cout << "Enter size for array1 - ";
    std::cin >> arr1Size;

    int *arr1 {new int[arr1Size]}; // dynamically created arr1

    std::cout << "Enter " << arr1Size << " elements separately" << std::endl;
    // element insertion
    for (size_t i{0}; i < arr1Size; ++i) {
        std::cin >> *(arr1 + i);
    }
    // display elements
    //print(arr1, arr1Size); // arr1 stores an address ie an reference and we cannot crete reference of an reference
    print(arr1, arr1Size);  // 

    // size of array2
    size_t arr2Size {};
    
    std::cout << "Enter size for array2 - ";
    std::cin >> arr2Size;

    int *arr2 {new int[arr2Size]}; // dynamically created arr2

    std::cout << "Enter " << arr2Size << " elements separately" << std::endl;
    // element insertion
    for (size_t i{0}; i < arr2Size; ++i) {
        std::cin >> *(arr2 + i);
    }
    // display elements
    print(arr2, arr2Size);  

    // dynamically created arr3
    int *arr3 = apply_all(arr1, arr1Size, arr2, arr2Size);
    // display arr3
    print(arr3, arr1Size * arr2Size);
    
    delete [] arr1;
    delete [] arr2;
    delete [] arr3;

    return 0;
}
