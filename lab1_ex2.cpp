#include <iostream>

int main() {
setlocale(LC_ALL, "Russian");

    int n,a,b,sum,pr;
    a = 1 ;
    b = 1;
    sum = 0;
    pr = b;
    std::cout << "Введите число n: ";
    std::cin >> n;
    while (a <= n) 
    {
        if ( a%2 == 0){
            sum = sum + a;
        }
        a++;
    }
    std::cout<<"Сумма четных чисел на промежутке [1;n] = "<<sum<< std::endl;
    while (b<=n){
        pr =pr*b;
        b = b+2;
    }
    std::cout<<"Произведение нечетных чисел на промежутке [1;n] = " <<pr<<std::endl;
    return 0;
}
