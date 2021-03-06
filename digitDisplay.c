#include <stdio.h>
#include <ctype.h>

#define MAX_DIGITS 10

/*external variables*/
const int segments[10][7] = {{1,1,1,1,1,1,0}, // 0
                             {0,1,1,0,0,0,0}, // 1
                             {1,1,0,1,1,0,1}, // 2
                             {1,1,1,1,0,0,1}, // 3
                             {0,1,1,0,0,1,1}, // 4
                             {1,0,1,1,0,1,1}, // 5
                             {1,0,1,1,1,1,1}, // 6
                             {1,1,1,0,0,0,0}, // 7
                             {1,1,1,1,1,1,1}, // 8
                             {1,1,1,1,0,1,1}};// 9
     /************
      *  _    0  *
      * |_|  561 *
      * |_|  432 *
      ************/
char digits[4][MAX_DIGITS * 4];

/*prototypes*/
void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main(void)
{
    clear_digits_array();
    
    char ch;
    printf("Enter a number: ");
    for(int i=0; i<MAX_DIGITS;){
        ch = getchar();
        if(isdigit(ch))
            process_digit( (int)(ch -'0') , i++);
        else if(ch == '\n')
            break;
        else
            continue;
    }
    
    print_digits_array();
    
    return 0;
}

void clear_digits_array(void)
{
    for(int i = 0; i<4; i++){
        for(int j = 0; j < MAX_DIGITS*4; j++){
            digits[i][j] = ' ';
        }
    }
}

void process_digit(int digit, int position)
{
    int row = 0;
    if(segments[digit][0]) digits[row][position*4 + 1] = '_';
    
    row = 1; 
    if(segments[digit][5]) digits[row][position*4 + 0] = '|';
    if(segments[digit][6]) digits[row][position*4 + 1] = '_';
    if(segments[digit][1]) digits[row][position*4 + 2] = '|';
    
    row = 2;
    if(segments[digit][4]) digits[row][position*4 + 0] = '|';
    if(segments[digit][3]) digits[row][position*4 + 1] = '_';
    if(segments[digit][2]) digits[row][position*4 + 2] = '|';
        
}

void print_digits_array(void)
{
    for(int i = 0; i<4; i++){
        for(int j = 0; j < MAX_DIGITS*4; j++){
            printf("%c" , digits[i][j]);
        }
        printf("\n");
    }
}
