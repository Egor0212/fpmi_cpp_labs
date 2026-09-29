#include <algorithm>
#include <iostream>
#include <vector>

size_t find(const std::string& text,
            const std::string& substr) {
    
}


int main() {

    int x;
    const int y = 5;

    const std::vector<int> cv = {1, 2, 3, 4, 5};
    std::sort(cv.begin(), cv.end());
    
    
    int* const cptr = nullptr; // const pointer
    const int* ptrc = nullptr; // ptr to const
    const int* const cptrc = nullptr;

    int z = 5;
    const int& rx = z;
    const int& r = 5;
    ++x; // ry = 6
    
    find("adasfadfae", "ada");

    return 0;
}
