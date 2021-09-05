#include <stdio.h>

/*********************************************************
 * prints an n X n magic square (a square arangement of  *
 * the numbers 1,2,...,n^2 in which the sums of the rows *
 * ,columns, and diagonals are all the same)             *
 * The user will specify the value of numbers            *
 * *******************************************************/
 
 /********************************************************
  * 이 프로그램에서 매직스퀘어를 만든 방법
  * 1. 1을 첫 행 가운데로 지정한다
  * 2. 이어서 다음 숫자를 전 숫자를 저장한 자리의 다음행,다음
  * 열에 저장한다
  * 3. 만약 행렬의 범위를 넘어가면 한바퀴 돌아서 반대쪽으로 
  * 돌아간다
  * 4. 만약 이미 원소가 있으면 방금 저장한 자리의 아래 자리에 
  * 저장한다
  * ******************************************************/
 

int main()
{
    
    int size;
    printf("이 프로그램은 사용자가 정의한 크기의 매직스퀘어를 출력합니다\n");
    printf("매직스퀘어의 한 변의 길이는 1부터 99까지의 홀수 중 하나입니다\n");
    printf("매직스퀘어의 한 변의 길이: ");
    scanf("%d", &size);
    
    int square[size][size]; //변의 길이가 size인 정사각배열을 정의하고 모든 값을 0으로 초기화하려고 했는데 초기화까지 하면 에러 뜸 엌ㅋㅋㅋ
    //반복문으로 초기화하기로 함
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            square[i][j] = 0;
        }
    }
    
    int ypos = 0, xpos = size/2; //초기 위치 정의
    int nexti = 2;
    //핵심 루프
    for(int i=1; i <=size*size;){
        if (square[ypos][xpos] == 0){
            square[ypos][xpos] = i++;
        }
        
        if(i == nexti){
            nexti++;
            if(ypos){
                if(square[ypos-1][(xpos+1)%size] == 0){
                    ypos--; xpos = ++xpos%size;
                    continue;
                }
                else{
                    if(ypos == size-1){
                        ypos = 0;
                        continue;
                    }
                    else{
                        ypos++;
                    }
                }
            }
            else{
                if(square[size-1][(xpos+1)%size] == 0){
                    ypos = size-1; xpos = ++xpos%size;
                    continue;
                }
                else{
                    if(ypos == size-1){
                        ypos = 0;
                        continue;
                    }
                    else{
                        ypos++;
                    }
                }
            }
        }
    }
    
    //매직스퀘어 출력
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            printf("%3d",square[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;
