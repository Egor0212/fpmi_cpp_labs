#include <iostream>
#include <optional> // c++17
#include <vector>


// 0 1 2 3 0 -> 6
// 1 2 3 0 5 -> no solution
// 1 2 3 4 5 -> no solution
// 1 0 0 3 4 -> no solution
std::optional<int32_t> FindSumBetweenZeros(const std::vector<int32_t>& v) {

    int first_zero = -1;
    for(size_t i = 0; i < v.size(); ++i) {
        if (v[i] == 0) {
            first_zero = i;
            break;
        }
    }
    if (first_zero == -1) {
        // return std::nullopt;
        throw "no zeros";
    }
    
    int last_zero = -1;
    for(size_t i = v.size() - 1; i >= 0u; --i) {
        if (v[i] == 0) {
            last_zero = i;
            break;
        }
    }

    if (last_zero == -1) {
        // return std::nullopt;
        throw "no zeros";
    }

    if (first_zero == last_zero) {
        // return std::nullopt;
        throw "array has only one zero";
    }

    if (first_zero + 1 == last_zero) {
        throw "no elements between zeros";
    }
    
    int32_t sum = 0;
    for (size_t i = first_zero; i <= last_zero; ++i) {
        sum += v[i];
    }
    return sum;
}



int main() {
    
    std::vector<int32_t> v{0,1,2,3,0};
    std::vector<int32_t> v1{0, -1, 1, 0};
    std::vector<int32_t> v2{1, 0, 0, 1};
    std::vector<int32_t> v3{1, 2, 3, 1};
    std::vector<int32_t> v4{1, 0, 3, 1};

    //std::cout << FindSumBetweenZeros(v) << '\n';
    //std::cout << FindSumBetweenZeros(v1) << '\n';
    //std::cout << FindSumBetweenZeros(v2) << '\n';
    //
    try {
        std::optional<int32_t> res = FindSumBetweenZeros(v4);
        std::cout << res.value();
    } catch(const char* msg) {
        std::cout << msg << '\n';
    }
    //if (res.has_value()) {
    //    std::cout << res.value();
    //} else {
    //    std::cout << "no solution :(";
    //}
}



