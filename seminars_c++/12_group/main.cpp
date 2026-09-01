#include <iostream>

// using namespace std;

int main() {
    // +, -, *, /, %   
    int n, m;
    std::cin >> n >> m;

    if (m == 1 || n == 1) {
        std::cout << 1;
    } else {
        for (int i = 2; i <= std::min(m, n); ++i) {
            if ((m % i == 0) && (n % i == 0)) {
                std::cout << i << ' ';
            }
        }
    }
    return 0;
}


