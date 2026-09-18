#include <cmath>
#include <iostream>


// [return_type] func_name(parameter_list) {code...}

bool IsPrime(int); // declaration

// double func(int, double);
// int func1();
// int func2(void);
// void func3(int);


int main() {
    std::cout << "Enter a number:\n";
    int num; // [type] name [= ...]
    if (!(std::cin >> num)) {
        std::cout << "expected a number\n";
        std::exit(-1);
    }

    bool res = IsPrime(num);
    if (res/*IsPrime(num)*/) {
        std::cout << "prime\n";
    }
    else {
        std::cout << "not prime\n";
    }
}

bool IsPrime(int num) {
    //bool is_prime = true;
    int sqrt_n = std::sqrt(num);
    for (int div = 2; div <= sqrt_n; ++div) {
        if (num % div == 0) {
            /*is_prime = false;
            break;*/
            return false;
        }
    }

    return true;
}
