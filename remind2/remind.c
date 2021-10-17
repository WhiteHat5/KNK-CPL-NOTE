#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readline.h"

#define MAX_REMIND 50
#define MSG_LEN 60

struct vstring {
	int len;
	char chars[]; /* flexible array member */
};

int main(void)
{
    struct vstring *reminders[MAX_REMIND];
    char time_str[12], msg_str[MSG_LEN+1];
    int day,month,hour, min, i, j, num_remind = 0;
    
    for(;;){
        if (num_remind == MAX_REMIND) {
            printf("--No space left --\n");
            break;
        } //리마인더 최대 저장 개수에 도달 시 루프 탈출
        
        //printf("Enter month/day, 24-hour time and reminder: "); //대화형 프로그램일 경우 시용
        scanf("%2d", &month);
        if(month == 0)
            break; //0 입력 시 루프 탈출
        scanf(" /%2d %2d :%2d", &day, &hour, &min);
        
        if(month < 1 || month > 12 || day < 1 || day > 31 || hour < 0 || hour > 23 || min < 0 || min > 59){
            printf("--Invalid time--\n");
            read_line(msg_str, MSG_LEN); //read line and discard it
            continue;
        } //잘못된 시간 입력 시 루프 다시 돌림
        
        sprintf(time_str,"%2d/%.2d %.2d:%.2d", month,day,hour,min); //time_str에 시간값 문자열 저장
        read_line(msg_str, MSG_LEN);
        
		reminders[num_remind] = malloc(sizeof(struct vstring) + 11 + strlen(msg_str));
		(reminders[num_remind])->len = strlen(msg_str) + 11;
		if (reminders[num_remind] == NULL) {
			printf("NO SPACE LEFT\n");
			break;
		}
		
        for(i=0; i<11; i++)
			(reminders[num_remind]->chars)[i] = time_str[i];
        for(i=0; i < reminders[num_remind]->len; i++)
			(reminders[num_remind]->chars)[i + 11] = msg_str[i];
        
        num_remind++;
    }
    
	
    printf("MM/DD hh:mm Reminder\n");
    for(i=0; i<num_remind; i++){
        for(j=0; j < reminders[i]->len ; j++)
			putchar((reminders[i]->chars)[j]);
		putchar('\n');
	}
    return 0;
}

