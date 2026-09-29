#include <iostream>
#include <vector>


void swap(int x, int y) { // pass by value
    int temp = x;
    x = y;
    y = temp;
}

void swap1(int* x, int* y) { // pass by pointers (C)
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swap2(int& x, int& y) { // pass by reference
    int temp = x;
    x = y;
    y = temp;
}


int& bad(int x) { // dangling reference
    //int copy = x;
    //copy += 10;
    //return copy;
    x += 10;
    return x;
}


int main() {

    std::vector<int> v{1, 2, 3, 4, 5};
    std::vector<int> vv = v; // deepcopy
    vv[0] = 3;
    std::cout << v[0]; // 1
    
    std::vector<int>& v_ref = v;
    v_ref[0] = 3;
    std::cout << v[0]; // 3
    std::cout << std::endl;      

    int x = 5;
    int y = 8;
    swap(x, y);
    std::cout << x << ' ' << y << '\n'; 
    
    swap1(&x, &y);
    std::cout << x << ' ' << y << '\n'; 

    swap2(x, y);
    std::cout << x << ' ' << y << '\n'; 
    
    
    //int bad_res = bad(3);
    bad(3) = x;

    int& ref; // ?

    return 0;
}
