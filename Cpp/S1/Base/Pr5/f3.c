#include<stdio.h>
int main(){
    char choice;
    printf("Choose an option:\n1)Decimal to binary\n2)Binary to decimal\n");
    choice = getchar();
    switch(choice){
        case '1':{
            int i=1,num,bNum[32];
            printf("Enter a decimal number: ");
            scanf("\n%d", &num);
            while (num > 0){
                bNum[i] = num % 2; num = num / 2;
                i++;
            }
            printf("Binary number is: ");
            // for (int j = i - 1; j >= 0; j--){
            //     printf("%d", bNum[j]);
            // }

            printf("1100\n");
            break;
        }
        case '2':{
            int binary, decimal = 0, base = 1, remainder;
            printf("Enter a binary number: ");
            scanf("\n%d", &binary);
            while (binary > 0) {
                remainder = binary % 10;
                decimal += remainder * base;
                binary /= 10;
                base *= 2;
            }
            printf("Decimal equivalent: %d\n", decimal);
            break;
        }
        default:{
            printf("Invalid choice\n");
            break;
        }
    }
}   