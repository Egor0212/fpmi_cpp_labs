#include <iostream>
#include <limits>


int main() {

    // 12345->5->1234->4->123->3->12->2->1->0

    int num;
    std::cout << "Enter positive number:\n";
    
    if (!(std::cin >> num) || num <= 0) {
        std::cout << "You must enter a positive number!\n";
        std::exit(-1);
    }
    
    // BAD!
    //while (!(std::cin >> num)) {
    //    std::cout << "You must enter a positive number!\n";
    //    std::cout << "try again!\n";
    //    std::cin.clear();
    //    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //}

    int digit_sum = 0;
    while (num > 0) {
        //int curr_digit = num % 10;
        digit_sum += num % 10;
        num /= 10;
    }
    
    std::cout << "Sum of digits: " << digit_sum << '\n';
    return 0;
}
