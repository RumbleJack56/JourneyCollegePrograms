#include <stdio.h>
double calcexp(double x) {
    double result = 1.;
    double term = 1.;
    int i;
    // Using the taylors expansion for e^x
    for (i = 1; i <= 10; i++){
        term *= x / i;
        result += term;
    }
    return result;
}

int main(){
    double x, result;
    printf("Enter a value for x: ");
    scanf("%lf", &x);

    result = calcexp(x);
    printf("e^%.2lf = %.4lf\n", x, result);
 
    return 0;
}
