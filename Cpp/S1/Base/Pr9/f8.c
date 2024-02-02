#include<stdio.h>
#include<string.h>
int main(){
    int n;
    printf("Enter number of words to enter:");
    scanf("%d",&n);                   while((getchar())!='\n');
    char charbuffer[n][50];
    for (int i=0;i<n;++i){
        printf("Enter Number %d for compare: ",i+1);
        fgets(charbuffer[i],50,stdin);
        char newline[]= "\n";
        charbuffer[i][strcspn(charbuffer[i],newline)] = '\0';
    }
    printf("Input Recieved...\n Comparison given below:\n\n");

    //Round Robin Algorithm
    for (int a=0; a<n-1;++a){
        for (int b=a+1;b<n;++b){
            printf("Comparison of %s and %s is %d \n",charbuffer[a],charbuffer[b],strcmp(charbuffer[a],charbuffer[b]));
        }
    }
    
}