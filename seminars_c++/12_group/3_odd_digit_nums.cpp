#include <iostream>

int main() {

    int a, b, ans = 0;

    std::cout << "Input first number: ";
    if (!(std::cin >> a) || a <= 0) {
        std::cout << "Error: wrong input";
        return 1;
    }
    std::cout << "Input second number ";
    if (!(std::cin >> b) || b <= 0 ) {
        std::cout << "Error: wrong input";
        return 1;
    }
    if (a > b) {
        int tr = a;
        a = b;
        b = tr;
    }

    for (int i = a; i <= b; i++) {
        int number = i;
        bool f = true;
        while (number > 0) {
            if ((number % 10) % 2 == 0)
            {
                f = false;
                break;
            }
            number /= 10;
        }
        if (f) {
            ans++;
            std::cout << i << std::endl;
        }
        
    }
    std::cout << "answer: " << ans;
    return 0;
}
