#include <stdio.h>
#include <ctype.h>
#define SIZEOFMESSAGE ((int)(sizeof(message))/(sizeof(message[0])))
int main(void) {
    
    int i;
    char message[40]; //여기에서 초기화해서 배열원소를 모두 0으로 만들면 이후 나올 루프에서 더 편하게 돌릴 수 있음
    
    printf("Enter message: ");
    for(i = 0; i < SIZEOFMESSAGE ; i++){
        scanf("%c",&message[i]);
        if (message[i] == '\n')
            break;
    }
    
    printf("In B1FF-speak: ");
    
    for(i = 0; i < SIZEOFMESSAGE ; i++){
        
        switch(message[i]){ 
            /*switch 문에서 인수부분에 바로 toupper를 박았으면 이후 체크할 때 대문자 소문자 둘 다 안해봐도 되고 toupper를 마지막에 안 써도 된다.
             * 위 글처럼 하면 모든 원소에 toupper를 적용해야 하는 대신 뒤의 소문자 체크를 안 해도 된다
             * 따라서 toupper와 switch 문 내에서 인수 체크에 걸리는 시간에 따라 속도에 차이가 날 듯
             */
            case'\n':
                goto loopEnd; // 위에서 배열을 초기화 했으면 이런 똥지랄을 안 해도 됐을 텐데 지금 수준에서는 이거말고 루프를 벗어날 수 있는 방법이 생각이 안 난다.
            case 'A': case 'a':
                printf("4");
                break;
            case 'B': case 'b':
                printf("8");
                break;
            case 'E': case 'e':
                printf("3");
                break;
            case 'I': case 'i':
                printf("1");
                break;
            case 'O': case 'o':
                printf("0");
                break;
            case 'S': case 's':
                printf("5");
                break;
            default:
                printf("%c", toupper(message[i]));
                break;
            
        }
        
    }
    loopEnd: 
    printf("!!!!!!!!!!\n");
    
    return 0;
}
