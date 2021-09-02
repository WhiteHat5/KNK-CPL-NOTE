#include <stdio.h>

int main()
{
    
    int result[5][5] = {0};
    int temp_total, j , i, score_max, score_min;
    
    for(i=0; i<5; i++){
        printf("Student %d: ",i+1);
        for(j=0; j<5; j++){
            scanf(" %d", &result[i][j]);
        }
    }

    printf("\n          Total Average\n");
    for(i=0; i<5; i++){
        temp_total=0;
        for(j=0; j<5; j++){
            temp_total+= result[i][j];
        }
        printf("Student%d: %6d%6.1f\n",i+1,temp_total,temp_total/5.0);
    }
    
    printf("\n      Average     High    Low\n");
    for(i=0; i<5; i++){
        temp_total=0;
        for(j=0; j<5; j++){
            temp_total+= result[j][i];
        }
        score_min = score_max = result[0][i];
        for(j=0; j<4; j++){
            if(result[j][i]>score_max)
                score_max = result[j][i];
            if(result[j][i]<score_min)
                score_min = result[j][i];
        }
        printf("Quiz%d: %6.1f%6d%6d\n",i+1,temp_total/5.0,score_max,score_min);
    }
    
    return 0;
}
