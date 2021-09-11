#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

int roll_dice(void);
bool play_game(void);
int main()
{
    char coin;
    int win = 0, loss = 0;
    
    srand((unsigned)time(NULL));
    
    do{
    if(play_game()){
        printf("You win!\n");
        win++;
    }
    else{
        printf("You lose!\n");
        loss++;
    }    
    
    printf("Play again?\n");
    //coin에 알파벳 입력이 들어와 저장될 때까지 반복
    while(!isalpha(coin = getchar())){
        
    }
    
    } while (coin == 'y');
    
    if(coin == 'n'){
            printf("\nWins: %d Losses: %d\n", win, loss);
            return 0;
    }
}

bool play_game(void){
    int roll, point;
    
    
    roll = roll_dice();
    printf("You rolled: %d\n", roll);
    
    switch(roll){
        case 7: case 11:
            return true;
        case 2: case 3: case 12:
            return false;
        default:
            printf("Your point is %d\n", roll);
            point = roll;
            break;
    }
    
    while( (roll = roll_dice()) != 7){
        if(roll == point){
            printf("You rolled %d\n", roll);
            return true;
        }
        else{
            printf("You rolled %d\n", roll);
        }
        
    }
    printf("You rolled %d\n", roll);
    return false;
    
}

int roll_dice(void){
    //srand((unsigned)time(NULL)); 원래 여기서 시드값 초기화하려고 했는데 프로그램 속도가 너무 빨라서(!!) 항상 같은 값으로 초기화되는 버그가 생긴 듯
    return (rand()%6 + rand()%6 + 2);
}
