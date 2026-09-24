#include <iostream>


void PrintArray(int* arr, size_t size) {
    std::cout << "\nYour array:\n";
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}



int main() {
    
    using std::cout;

    int a[5] = {1, 2, 3, 4, 5}; // static array
    cout << a[2] << '\n'; // 3

    int *p = a; // array-to-pointer conversion
    cout << p[2]; // cout << *(p + 2); // 3
    // a[2] = *(a + 2) = *(2 + a)  = 2[a]
    
    int* k = &a[2];
    cout << k[-1]; // *(k - 1) = 2

    int b[5];
    // b = a; // CE
    
    cout << sizeof(a); // 20
    cout << sizeof(p); // 8

    int size = sizeof(a) / sizeof(a[0]);
    cout << size; // 5
    

    //------------------------------
    int* darr = new int[5]; // dynamic array
    for (size_t i = 0; i < 5; ++i) {
        darr[i] = i * i;
    }

    PrintArray(darr, 5);
    PrintArray(a, 5);


    // int* ptr = nullptr;
    // darr = ptr;

    delete[] darr;



    return 0;
}
