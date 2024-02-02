    #include<stdio.h>
    int main(){ 
        int num;
        printf("Enter Number: ");
        scanf("%d", &num);
        int rev=0,temp=num;
        while (num!=0){
            rev=10*rev+num%10;
            num/=10;}
        printf("Reverse of number %d is %d",temp,rev);
        return 0;
    }