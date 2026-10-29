#include <iostream>
#include <optional>
#include <vector>


// 0 1 2 3 0 -> 6
// 1 2 3 0 4 -> no solution
// 1 2 3 4 5 -> no solution
// 1 2 0 0 3 -> no solution
int32_t FindSumBetweenZeros(const std::vector<int32_t>& v) {
    int first_zero = -1;
    for (size_t i = 0; i <  v.size(); ++i) {
        if (v[i] == 0) {
            first_zero = i;
            break;
        }
    }

    if (first_zero == -1) { // no zeros
        // return std::nullopt;
        throw "no zeros in array";
    }

    int last_zero = -1;
    for (size_t i = v.size() - 1; i >= 0u; --i) {
        if (v[i] == 0) {
            last_zero = i;
            break;
        }
    }

    if (last_zero == -1) { 
        //std::cerr << "no solution";
        //std::exit(-1);
        //
        //return std::nullopt;
        throw "no zeros in array";
    }

    if (first_zero == last_zero) {
        throw "array has only one zero";
    }

    if (first_zero + 1 == last_zero) {
        throw "no elements between zeros";
    }
    
    int32_t sum = 0;
    for (int i = first_zero; i <= last_zero; ++i) {
        sum += v[i];
    }
    return sum;
}



int main() {

    std::vector<int32_t> v{0, 1, 3, 0};
    std::vector<int32_t> v1{1,2,3,4};
    std::vector<int32_t> v2{1,2,0,7};
    std::vector<int32_t> v3{1,0,0,1};
    try {
        std::cout << FindSumBetweenZeros(v2);
        //std::optional<int32_t> sum = FindSumBetweenZeros(v);
        //if (sum.has_value()) {
        //    std::cout << sum.value();
        //} else {
        //    std::cout << "no solution";
        //}
    } catch (const char* msg) {
        std::cout << msg;
    }

}

