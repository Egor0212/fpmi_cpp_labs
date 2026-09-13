#include <cassert>


int main() {

    double a = 0.1; // 0.100000000001
    double b = 0.2; // 0.200000000009

    double sum = a + b; // 0.3.....1
    //assert(sum == 0.3); // fail
    
    assert(std::fabs(sum - 0.3) < 1e-10); // ?

    return 0;
}
