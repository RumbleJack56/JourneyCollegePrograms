#include<stdio.h>
void flush(){
    while ((getchar()) != '\n');
}
void calculator(){
    char oper;
    start:
    printf("\nWelcome to Calculator:\nFor Addition press a \nFor Subtraction press s \nFor Multiplication press m \nFor Division press d \nQuit by q \nInput: ");
    scanf("%c",&oper);
    flush();

    int n1,n2;
    switch(oper){
        case 'a':
        printf("Addition Selected\nEnter two numbers seperated by spaces: ");
        scanf("%d %d",&n1,&n2);
        flush();
        printf("%d + %d = %d",n1,n2,n1+n2);
        break;



        case 's':
        printf("Subtraction Selected\nEnter two numbers seperated by spaces: ");
        scanf("%d %d",&n1,&n2);
        flush();
        printf("%d - %d = %d",n1,n2,n1-n2);
        break;



        case 'm':
        printf("Multiplication Selected\nEnter two numbers seperated by spaces: ");
        scanf("%d %d",&n1,&n2);
        flush();
        printf("%d x %d = %d",n1,n2,n1*n2);
        break;



        case 'd':
        printf("Addition Selected\nEnter two numbers seperated by spaces: ");
        scanf("%d %d",&n1,&n2);
        flush();
        printf("%d / %d = %f",n1,n2,((float)n1)/n2);
        break;


        case 'q':
        goto donehere;
        break;

        default:
        printf("Invalid Input try Again");
        goto start;
    }
    
    printf(" ");
    donehere:
    printf(" ");
}
int main(){

    calculator();
    return 0;
}