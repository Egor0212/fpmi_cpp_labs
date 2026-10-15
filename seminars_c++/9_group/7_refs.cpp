#include <iostream>
#include <vector>

void Input(int& m, int& n) {
    std::cin >> m;
    std::cin >> n;
}


int& bad(int x) { // dangling reference
    x += 10;
    return x;
}


size_t find(const std::string& text, const std::string& substr);


int main() {

    std::vector<int> v{1,2,3,4,5};    
    std::vector<int>& vv = v;

    int x = 5;
    int& rx = x;
    int& rrx = x;
    ++rx;
    ++rrx;
    std::cout << x;

    vv[0] = 2;
    std::cout << v[0];

    int m = 2, n = 3;
    
    Input(m, n);
    std::cout << m << n;

    int y = bad(3);
    std::cout << y; // 13

    return 0;
}
