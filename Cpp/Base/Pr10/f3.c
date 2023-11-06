#include<stdio.h>
#include<string.h>

int main(){
    union stud{
        char name[20];
        long double value;
        int a;
    };
    union stud ujju;
    strcpy(ujju.name,"Ujjwal");
    printf("%d      %d     %d     %d",sizeof(ujju.name),sizeof(ujju.value),sizeof(ujju.a),sizeof(ujju));
    return 0;
}