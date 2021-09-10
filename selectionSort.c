#include <stdio.h>

void selection_sort(int [], int);

int main(void){
    int n;
    printf("Enter the length of the array: ");
    scanf(" %d", &n);
    int a[n];
    printf("Enter a series of integer: ");
    
    for(int i = 0; i < n; i++){
        scanf(" %d", &a[i]);
    }
    
    
    
    selection_sort(a, n);
    
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}

void selection_sort(int a[], int n){
    int temp;
    
    for(int i = 0; i<n; i++){
        if(a[n-1] < a[i]){
            temp = a[n-1];
            a[n-1] = a[i];
            a[i] = temp;
        }
    }
    
    if(n>0)
        selection_sort(a, n-1);
    
}
