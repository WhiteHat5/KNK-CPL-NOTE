#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void){
    int n;
    float result = 1.0f;

    printf("This program prints out the approximation of the mathematical constant e by adding a series from 1 to n\ne = 1 + 1/1! + 1/2! + 1/3! + ... + 1/n!\n\n");
    printf("Enter the value of n: ");
    scanf("%d", &n);

    for(int i=0 , fact = 1; i<n ; i++){
        result += 1.0f/fact;
        fact *= i+2;
    }

    printf("The approximated value of e is %f", result);

    return 0;
}
