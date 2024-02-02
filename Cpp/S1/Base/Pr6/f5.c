#include<stdio.h>


float areaCircle(float r){
    float pi = 3.1415926535;
    return pi*r*r;
}


// the int does not matter, its only part of the format
int main(){
    float rad;
    printf("Enter radius of circle: ");
    scanf("%f",&rad);
    float ar = areaCircle(rad);
    printf("area of circle of radius %.2f is %.2f sq units",rad,ar);
    printf("area of circle of radius %.2f is %.2f sq units",rad,areaCircle(rad));
}