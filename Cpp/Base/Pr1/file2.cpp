#include<iostream>
namespace parallel{
    int x = 5;
}
int x= 10;
int main(){
    int x = 51;

    std::cout << x << std::endl;

    std::cout << parallel::x << std::endl;
}