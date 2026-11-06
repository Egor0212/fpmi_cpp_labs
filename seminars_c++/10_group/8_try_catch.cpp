#include <iostream>
#include <numeric>
#include <optional>
#include <vector>


int64_t FindSumBetweenZeros(const std::vector<int32_t>& v) {
    if (v.empty()) {
        throw "Error: array has no elements!!!";
    }
    
    std::optional<size_t> first_zero;
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] == 0) {
            first_zero = i;
            break;
        }
    }
    
    std::optional<size_t> last_zero;
    for (size_t i = v.size(); i > 0u; --i) {
        if (v[i - 1] == 0) {
            last_zero = i - 1;
            break;
        }
    }

    if (!first_zero.has_value() || !last_zero.has_value()) {
        throw "Error: array has no no zeros!!!";
    } else if (first_zero.value() == last_zero.value()) {
        throw "Error: array has only one zero!!!";
    } else if (*first_zero + 1 == *last_zero) {
        throw "Error: no elements between zeros";
    } else {
        return std::accumulate(v.begin() + *first_zero, v.begin() + *last_zero, int64_t{});
    }
}



int main() {
    
    std::vector<int32_t> v{0, 1, 2, 3, 0}; // 6
    std::vector<int32_t> v1{0, -1, 1, 0}; // 0
    std::vector<int32_t> v2{1, 0, 0, 1}; // no solution
    std::vector<int32_t> v3{1, 2, 3, 1}; // no solution
    std::vector<int32_t> v4{1, 0, 3, 1}; // no solution
    std::vector<int32_t> empty; // empty

    try {
        std::cout << FindSumBetweenZeros(v) << '\n';
        std::cout << FindSumBetweenZeros(v1) << '\n';
    } catch(const char* msg) {
        std::cout << msg << '\n';
    }
    
    try {
        std::cout << FindSumBetweenZeros(v2) << '\n';
    } catch(const char* msg) {
        std::cout << msg << '\n';
    }

    try {
        std::cout << FindSumBetweenZeros(v3) << '\n';
    } catch(const char* msg) {
        std::cout << msg << '\n';
    }
    
    try {
        std::cout << FindSumBetweenZeros(v4) << '\n';
    } catch(const char* msg) {
        std::cout << msg << '\n';
    }
    
    try {
        std::cout << FindSumBetweenZeros(empty) << '\n';
    } catch(const char* msg) {
        std::cout << msg << '\n';
    }
}



