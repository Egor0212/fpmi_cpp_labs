#include <iostream>


int main() {

    int arr[5] = {1, 2, 3, 4, 5}; // static array
    // int* arr = new int[5]{}; // dynamic  array
    std::cout << arr[2]; // 3
    int* arr_ptr = arr; // array-to-pointer conversion
    std::cout << arr_ptr[2]; // *(arr_ptr + 2)
    
    // arr[2] = *(arr+2) = *(2+arr) = 2[arr]
    
    int* k = &arr[2];
    std::cout << k[-1]; // *(k-1)=2

    int b[5];
    // b = arr; // CE!

    for (size_t i = 0; i < 5; ++i) {
        b[i] = arr[i] * arr[i];
    }

    for (size_t i = 0; i < 5; ++i) {
        std::cout << b[i] << ' ';
    }

    std::cout << sizeof(arr); // 20
    std::cout << sizeof(arr_ptr); // ?
    delete[] arr;

    return 0;
}
