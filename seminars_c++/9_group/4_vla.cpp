#include <iostream>

const int MAX_LENGTH = 100'000;

int main() {
    
    int arr[MAX_LENGTH];

    int n;
    std::cin >> n;
    // int a[n]; // vla --- variable length array
                 // vla --- ne ok
    
    // int* arr = new int[n]; // ok

    if (n > MAX_LENGTH) {
        std::cout << "error!\n";
        std::exit(-1);
    }

    for (size_t i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    for (size_t i = 0; i < n; ++i) {
        std::cout << arr[i] << ' ';;
    }

    // delete[] arr;

    return 0;
}
