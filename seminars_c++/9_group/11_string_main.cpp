#include <iostream>

#include "11_string.h"


int main() {
    
    String s;
    std::cout << s << '\n';
    String s1(8, 'a');
    std::cout << s1 << '\n';
    String s2(s1);
    std::cout << s2 << '\n';

    s = s2; // s.operator=(s2);
    std::cout << s << '\n';
    s1 = s2;
    std::cout << s1 << '\n';
}
