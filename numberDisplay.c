#include <stdio.h>
#include <stdbool.h>

int main()
{
    const int segments[10][7] = {{1,1,1,1,1,1,0}, {0,1,1,0,0,0,0}, {1,1,0,1,1,0,1}, {1,1,1,1,0,0,1}, {0,1,1,0,0,1,1}, {1,0,1,1,0,1,1}, {1,0,1,1,1,1,1}, {1,1,1,0,0,0,0}, {1,1,1,1,1,1,1}, {1,1,1,1,0,1,1}};
    int numberToPrint;
    
    for(;;){
        printf("숫자를 입력하시오: ");
        scanf(" %1d",&numberToPrint);
        if(segments[numberToPrint][0]){
        printf(" _\n");
        }
        else{
            printf("\n");
        }   
        if(segments[numberToPrint][5]){
            printf("|");
        }
        else{
            printf(" ");
        }
        if(segments[numberToPrint][6]){
            printf("_");
        }
        else{
            printf(" ");
        }
        if(segments[numberToPrint][1]){
            printf("|\n");
        }
        else{
            printf("\n");
        }
        if(segments[numberToPrint][4]){
            printf("|");
        }
        else{
            printf(" ");
        }
        if(segments[numberToPrint][3]){
            printf("_");
        }
        else{
            printf(" ");
        }
        if(segments[numberToPrint][2]){
            printf("|\n");
        }
        else{
            printf("\n");
        }
    }

    return 0;
}
