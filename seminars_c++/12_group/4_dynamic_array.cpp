#include <iostream>


int main() {
    int* p;

    int* darr = new int[5];
    int* copy = darr;

    delete[] copy;
    delete[] darr; 

    int n;
    std::cin >> n;
    int* arr = new int[n];
    delete[] arr;

    return 0;
}
