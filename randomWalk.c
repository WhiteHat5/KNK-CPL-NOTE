#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
int main(void){
    int i , j, direction, move=0;
    char board[10][10];
    bool blocked[4] = {false};
    
    srand((unsigned)time(NULL));
    
    /*Initialization of the board*/
    for(i=0; i<10; i++){
        for(j=0; j<10; j++){
            board[i][j] = '.';
        }
    }
    
    //main loop
    i=0, j=0;
    board[0][0] = 'A';
    for(;;){
        if(move==25)
            break; //z도달 시 루프 탈출
        if(blocked[0]&&blocked[1]&&blocked[2]&&blocked[3])
            break; // 네 방향 모두 막혔을 때 루프 탈출
        direction = rand() % 4; //방향 랜덤 설정
        switch(direction){
            case 0: //up
                if(blocked[0])
                    break;
                else if(i==0||board[i-1][j]!='.'){ //오류가 날 것 같긴 한데 OR에서 앞에 조건이 맞으면 바로 종료될 거라서 뒤의 조건이 오류를 일으키는 경우가 없을 것이라고 예상
                    blocked[0] = true;
                    break;
                }
                else {
                    i--;
                    board[i][j] = 'A' + move + 1;
                    move++;
                    for(int m=0; m<4; m++){
                        blocked[m] = false; // 블록 배열 초기화
                    }
                    break;
                }
            case 1: //right
                if(blocked[1])
                    break;
                else if(j==9||board[i][j+1]!='.'){
                    blocked[1] = true;
                    break;
                }
                else {
                    j++;
                    board[i][j] = 'A' + move + 1;
                    move++;
                    for(int m=0; m<4; m++){
                        blocked[m] = false; // 블록 배열 초기화
                    }
                    break;
                }
            case 2: //down
                if(blocked[2])
                    break;
                else if(i==9||board[i+1][j]!='.'){
                    blocked[2] = true;
                    break;
                }
                else {
                    i++;
                    board[i][j] = 'A' + move + 1;
                    move++;
                    for(int m=0; m<4; m++){
                        blocked[m] = false; // 블록 배열 초기화
                    }
                    break;
                }
            case 3: //left
                if(blocked[3])
                    break;
                else if(j==0||board[i][j-1]!='.'){
                    blocked[3] = true;
                    break;
                }
                else {
                    j--;
                    board[i][j] = 'A' + move + 1;
                    move++;
                    for(int m=0; m<4; m++){
                        blocked[m] = false; // 블록 배열 초기화
                    }
                    break;
                }
            default: 
                break;
        }
    }
    
    for(i=0;i<10;i++){
        for(j=0; j<10; j++){
            printf("%c",board[i][j]);
        }
        printf("\n");
    }
}
