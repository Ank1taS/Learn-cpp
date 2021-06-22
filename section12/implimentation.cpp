// implimentation of functions
#include "header.h"

void print(int * const &array, size_t size) {
    for (size_t i {}; i < size; ++i) {
        std::cout << *(array + i) << "\t"; 
    }
    std::cout << std::endl;
}

int* apply_all(int* const &arr1, size_t arr1Size , int* const &arr2, size_t arr2Size) {
    size_t newSize = arr1Size * arr2Size; 

    // dynamically created arr3
    int *arr3 {new int[newSize]};

    newSize = 0;
    // impimentation - arr1 * arr2
    for (size_t i {}; i < arr2Size; ++i) {
        for (size_t j {}; j < arr1Size; ++j) {
            arr3[newSize++] = arr1[j] * arr2[i];
        }
    }

 //   int *arrTemp = arr3;

    //delete arr3 
 //   delete [] arr3;
    
    return arr3;
}
