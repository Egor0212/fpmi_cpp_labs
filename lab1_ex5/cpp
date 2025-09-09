#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Введите два числа: ";
    cin >> n >> m;

    cout << "Общие делители чисел " << n << " и " << m << ": ";

    int limit = (n < m) ? n : m; // минимум из n и m

    for (int i = 1; i <= limit; i++) {
        if (n % i == 0 && m % i == 0) {
            cout << i << " ";
        }
    }

    cout << endl;
    return 0;
}
