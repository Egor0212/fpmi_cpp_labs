#include <iostream>
#include <cmath> // для pow

using namespace std;

long long sum(int n) {
    long long s = 0;
    for (int i = 1; i <= n; i++) {
        s += pow(i, i); // i^i
    }
    return s;
}

int main() {
    int n;

    cout << "Введите n: ";
    cin >> n;

    cout << "Сумма s = ";
    cout << sum(n) << endl;

    // Проверим для маленьких n
    cout << "n=5  -> " << sum(5) << endl;
    cout << "n=6  -> " << sum(6) << endl;
    cout << "n=10 -> " << sum(10) << endl;

    return 0;
}
