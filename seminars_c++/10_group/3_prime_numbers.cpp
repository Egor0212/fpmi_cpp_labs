#include<cmath>
#include <iostream>


//[return_type] func_name(parameters_list){code...}

bool IsPrime(int); // declaration

//void func(int, double);
//void func1(void);
//void func2();


int main() {
	std::cout << "enter	a number:\n";
	int n; // =0
	std::cin >> n;

	if (IsPrime(n)) {
		std::cout << "prime\n";
	}
	else {
		std::cout << "not prime\n";
	}

	return 0;
}

bool IsPrime(int num) {
	//bool is_prime = true;
	int sqrt_n = std::sqrt(num);
	for (int div = 2; div < sqrt_n; ++div) {
		if (num % div == 0) {
			//is_prime = false;
			return false;
		}
	}
	return true;
}