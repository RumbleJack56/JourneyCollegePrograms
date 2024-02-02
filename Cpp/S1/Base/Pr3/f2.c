#include<stdio.h>

int main(){
    char a,b;
    printf("Do you love your father? (y/n)    ");
    scanf("%c",&a);
    printf("Do you love your mother? (y/n)    ");
    scanf("\n%c",&b);
    printf("\n");

    if ((a=='y') && (b=='y')){
        printf("you are a good child.\n");
    }
    if ((a=='y') || (b=='y')){
        printf("Atleast you love someone.\n");
    }
    if (!((a=='y') || (b=='y'))){
        printf("I'm there for you dont worry...");
    }
}