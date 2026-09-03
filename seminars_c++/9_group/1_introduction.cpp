#include <iostream>


int main() {
    
    using std::cin;
    using std::cout;
    
    int n, m;

    cout << "Enter positive n, m:" << std::endl;
    cin >> n >> m;

    if ((n <= 0) || (m <= 0)) {
        cout << "n,m must  be positive!\n";
        return -1;
    }

    // i [2, min(n,m)]
    
    cout << 1 << ' ';

    int min = std::min(n, m);
    for (int i = 2; i <= min; ++i) {
        if ( (m % i == 0) && (n % i == 0) ) {
            cout << i << ' ';
        }
    }

    return 0;
}
