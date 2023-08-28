#include<iostream>
#include<stdio.h>

using namespace std;

int main(){ 
    int num;

    cout << "Enter Number: ";
    scanf("%i", &num);


    int tem=num,rem=0;

    while (num!=0){

        rem=10*rem + num%10; 

        num = ( num - num%10)/10;
    }
    
    if (tem==rem){
        cout << "Number is a palindrome" << endl;

    }
    else{
        cout << "Number is not a palindrome" << endl;

    }



    return 0;
}