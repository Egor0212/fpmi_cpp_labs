#include <iostream>
#include <optional> // c++17
#include <vector>

// 0 1 2 3 0 -> 6
// 1 2 3 4 5 -> no solution
// 1 2 0 4 5 -> no solution
// 1 2 0 0 5 -> no solution
int32_t FindSumBetweenZeros(const std::vector<int32_t>& v) {
    int first_zero = -1;
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] == 0) {
            first_zero = i;
            break;
        }
    }
    if (first_zero == -1) {
        //std::cout << "Error: array has no zeros!!!";
        //std::exit(-1);
        // return -1;
        //return std::nullopt;
        throw "Error: array has no zeros!!!";
    }

    int last_zero = -1;
    for (size_t i = v.size() - 1; i >= 0u; --i) {
        if (v[i] == 0) {
            last_zero = i;
            break;
        }
    } 
    
    if (last_zero == -1) {
        throw "Error: array has no zeros!!!";
    }
    
    if (first_zero == last_zero) {
        throw "Error: array has only one zero!!!";
    }

    if (first_zero + 1 == last_zero) {
        
        //return -1;
        //return std::nullopt;
        throw "Error: no elements between zeros!!!";
    }
    
    int32_t sum = 0;
    for (int i = first_zero; i <= last_zero; ++i){
        sum += v[i];
    }
    return sum;
}



int main() {

    std::vector<int32_t> v{0, 1, 2, 3, 0};
    std::vector<int32_t> v1{1, 2, 3, 0, 5};
    std::vector<int32_t> v2{0, 3, -4, 0};
    std::vector<int32_t> v3{1, 2, 3, 4, 5};
    std::vector<int32_t> v4{0,0,1,2,3};
    
    try {
        int32_t sum = FindSumBetweenZeros(v4);
        std::cout << "sum = " << sum;
        //if (sum.has_value()) {
        //    std::cout << sum.value();
        //} else {
        //    std::cout << "oshibka :(";
        //}
    } catch(const char* msg) {
        std::cout << msg;
    }
}


