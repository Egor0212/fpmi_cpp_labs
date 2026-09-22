#include <iostream>

const int MAX_LENGTH = 100'000;

// type name [= target_value] --- variable
// [return_type] func_name(parameter_list); [{ code ...}]

void PrintArray(int*, size_t); // declaration

int main() {

    int arr[10]; // array of 10 elements of int

    int* parr = arr; // array-to-pointer conversion


    int a[5] = {1, 2, 3, 4, 5};
    int* p = a;

    std::cout << a[2]; // 3
    std::cout << p[2]; // 3
    // a[2] = *(a + 2) = *(2 + a) = 2[a]
    
    int* k = &a[2];
    std::cout << *k; // 3
    std::cout << k[-2]; // 1
    std::cout << a[100]; // UB
    // std::cout << a[1'000'000];
    
    std::cout << sizeof(int); // ~4
    std::cout << '\n' << sizeof(a); // 20
    std::cout << '\n' << sizeof(p); // 8
    
    // -------------------------------------
    std::cout << "\n---------------------\n"; 
    int array[MAX_LENGTH];
    int n;
    std::cin >> n;
    if (n > MAX_LENGTH) {
        std::cout << "fsdfsrgrsg";
        std::exit(-1);
    }

    for (size_t i = 0; i < n; ++i) {
        std::cin >> array[i];
    }
    
    PrintArray(array, n);


    return 0;
}


void PrintArray(int* arr, size_t size) { // definition
    // n = sizeof(arr) / sizeof(arr[0])
    std::cout << "\n Your array:\n";
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << ' ';
    }
}




