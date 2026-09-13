#include <cmath>
#include <iomanip>
#include <iostream>


int main() {

    int n = 20;
    double eps = std::pow(10, -n);
    double x = 1.0;

    double res = 0.0;
    double a_n = 1.0;
    int k = 1;

    while (std::fabs(a_n) >= eps/*|a_n| >= eps*/) {
        res += a_n;
        a_n *= x;
        a_n /= k;
        ++k;
    }

    std::cout << std::setprecision(n);
    std::cout << "my exp: " << res << '\n';
    std::cout << "stdexp: " << std::exp(x) << '\n';

    return 0;
}
