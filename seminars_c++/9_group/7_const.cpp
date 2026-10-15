#include <algorithm>
#include <iostream>


size_t find(const std::string& text, const std::string& substr);


int main() {

    int x = 5;
    const int& rx = x;
    x += 5; // rx = 10
    // rx += 10; // CE
    const int& y = 5;

    const int arr[5] = {1,2,3,4,5};
    std::sort(arr, arr + 5);

    int* prt;
    const int* ptrc = &x;
    ptrc = nullptr;
    *prtc = 5;

    int* const cptr;

    const int* const cptrc = &x;

    
    return 0;
}
