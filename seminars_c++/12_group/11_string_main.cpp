#include "11_string.h"


int main() {
    String s;
    String s1(10, 'a');
    std::cout << s1 << '\n';

    String s2 = s1; // copy ctor!!!
    std::cout << s2 << '\n';
    s1 = s2;

    String s3{'a', 'b', 'c', 'd'}; // abcd
    std::cout << s3 << '\n';

}