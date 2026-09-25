#include <iostream>


int main()  {


    int* p;
    std::cout << p << '\n'; 
    // std::cout << *p; // UB 
    
    int x = 5;
    int* px = &x;
    std::cout << *px;

    std::cout << *(px + 5); // px + 1 * sizeof(int) UB!

    int y = 0;

    int* zero_ptr = 0;
    std::cout << zero_ptr;
    zero_ptr = NULL; // NULL = (void*)(0)
    std::cout << zero_ptr;
    zero_ptr = nullptr; // std::nullptr_t
    

    int* d = new int(5);
    std::cout <<'\n' << d; 
    delete d;
    d = nullptr;
    std::cout <<'\n' << *d; 

    return 0;
}
