#include "11_string.h"


int main() {
    String s_empty;
    std::cout << s_empty << '\n';
    String s(4, 'b');
    std::cout << s << '\n';
    String s1(8, 'a');
    std::cout << s1 << '\n';
    String s2 = s1; // String s2(s1);
    std::cout << s2 << '\n';
    s = s1; // s.operator=(s1);
    std::cout << s << '\n';

    String s_init{'a', 'b', 'c', 'd', 'e', 'f'}; // abcdef
    std::cout << s_init; 
    //const String cs(50, 'c');
    //cs[2] = 5; // CE
}
