#include <stdio.h>

int main()
{
    
    int i;
    
    printf("This program prints a table of squares.\n");
    
    for(i =1;; i++){
        printf("%20d%20d\n",i, i*i);
        if (i%24==0){
            printf("Press Enter to continue...\n");
            getchar();
        }
    }
    return 0;
}
