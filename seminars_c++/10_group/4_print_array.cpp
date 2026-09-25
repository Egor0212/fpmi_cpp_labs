#include <iostream>

const size_t MAX_LENGTH = 100'000;

void PrintArray(int* arr, size_t size) {
    std::cout << "\nYour array:\n";
    for (size_t  i = 0; i < size; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}


int main() {

    int arr[MAX_LENGTH];
    // int N = sizeof(arr) / sizeof(arr[0]);

    int n;
    
    if (n > MAX_LENGTH) {
        std::cout << "error!";
        std::exit(-1);
    }

    // int* arr = new int[n];

    std::cin >> n;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // int arr[n]; // vla --- variable length array
    PrintArray(arr, n); // print array to cout

    // delete[] arr;

    return 0;
}
