#include <iostream>

// i \in [2; min(n, m)]
// if n % i == 0, m % i == 0

/*if (...) {
    // code 1
} else {
    // code 2
}*/


int main() {
    
    using std::cout;
    using std::cin;

    int n, m;
    cout << "Enter two positive nnumres n, m:" << std::endl;
    cin >> n >> m;

    if ((n <= 0) || (m <= 0)) {
        cout << "m, n must be positive!!!";
        return -1;
    }

    int min = std::min(n, m);
    cout << "Common dividers: " << 1 << ' ';
    for (int i = 2; i <= min; ++i) {
        if ((n % i == 0) && (m % i == 0)) {
            cout << i << ' ';
        }
    }

    return 0;
}
