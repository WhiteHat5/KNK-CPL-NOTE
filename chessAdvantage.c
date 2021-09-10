#include <stdio.h>

int evaluate_position(char board[8][8]);

int main()
{
    printf("Hello World");

    return 0;
}

int evaluate_position(char board[8][8]){
    int i,j, advantage = 0;
    
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            switch(board[i][j]){
                case 'Q':
                    advantage += 9;
                    break;
                case 'R':
                    advantage += 5;
                    break;
                case 'B':
                    advantage += 3;
                    break;
                case 'N':
                    advantage += 3;
                    break;
                case 'P':
                    advantage += 1;
                    break;
                case 'q':
                    advantage -= 9;
                    break;
                case 'r':
                    advantage -= 5;
                    break;
                case 'b':
                    advantage -= 3;
                    break;
                case 'n':
                    advantage -= 3;
                    break;
                case 'p':
                    advantage -= 1;
                    break;
                default:
                    break;
                    
            }
        }
    }
    
    return advantage;
}
