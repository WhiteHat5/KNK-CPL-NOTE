#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int read_line(char str[], int n);

int main(void)
{
    char reminders[MAX_REMIND] [MSG_LEN+12];
    char time_str[12], msg_str[MSG_LEN+1];
    int day,month,hour, min, i, j, num_remind = 0;
    
    for(;;){
        if (num_remind == MAX_REMIND) {
            printf("--No space left --\n");
            break;
        } //리마인더 최대 저장 개수에 도달 시 루프 탈출
        
        printf("Enter month/day, 24-hour time and reminder: ");
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
        
        for (i = 0; i < num_remind; i++)
            if (strcmp(time_str, reminders[i]) < 0)
                break;
        for (j = num_remind; j > i; j--)
            strcpy(reminders[j], reminders[j - 1]);
        
        strcpy(reminders[i], time_str);
        strcat(reminders[i], msg_str);
        
        num_remind++;
    }
    
    printf("\nMM/DD hh:mm Reminder\n");
    for(i=0; i<num_remind; i++)
        printf("%s\n", reminders[i]);
    
    return 0;
}

int read_line(char str[], int n)
{
    int ch, i = 0;
    
    while((ch = getchar()) != '\n')
        if(i<n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}
