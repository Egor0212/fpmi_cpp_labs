#include <iostream>
int main(){
    setlocale(LC_ALL, "Russian");
    int a,n,sum;
    a = 1;
    std::cout<<"Введите количество чисел n"<<std::endl;
    std::cin>>n;
    while ( a <= n){
        if ( a%2 > 0){
            sum = sum + a;
        }
        a++;
    }
    std::cout<<"Сумма первых нечетных n чисел = "<<sum<<std::endl;
	return 0;
}
