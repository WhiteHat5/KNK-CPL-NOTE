#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void){
    float result = 1.0f, sigma;

    printf("This program prints out the approximation of the mathematical constant e by adding a series until the smallest term is less than sigma\ne = 1 + 1/1! + 1/2! + 1/3! + ... + 1/n!\n\n");

    printf("Enter the value of sigma: ");
    scanf("%f", &sigma);

    for(int i=0 , fact = 1; 1.0f/fact > sigma ; i++){
        result += 1.0f/fact;
        fact *= i+2;
    }

    printf("The approximated value of e is %f", result);

    return 0;
}
