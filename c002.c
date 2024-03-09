#include <stdio.h>

int main()
{ 

    int person[4][3] = {0}; // 4개 층별 3개 호실의 점호 인원 수
    int sum[3] = {0};       // ( , , ) 점호 인원 수 합계 남 여 전체
    float ratio[3] = {0};   // ( , , ) 점호 인원 수 비율 남 여 전체
    int i = 0, j = 0;         // 반복문을 위한 변수

    //Input information!
    printf("Check room (Men)\n");
    for(i = 0; i < 2; i++){
        for(j = 0; j < 3; j++){
            printf("Room #%d0%d > ", i + 1, j + 1);
            scanf("%d", &person[i][j]);
            sum[0] += person[i][j];
        }
    }

    printf("Check room (Women)\n");
    for(i = 2; i < 4; i++){
        for(j = 0; j < 3; j++){
            printf("Room #%d0%d > ", i + 1, j + 1);
            scanf("%d", &person[i][j]);
            sum[1] += person[i][j];
        }   
    } 
    //Calculate the sum, ratio.etc....!!     
    sum[2] = sum[0] + sum[1]; 
    
    ratio[0] = (float)sum[0] / 24 * 100;
    ratio[1] = (float)sum[1] / 24 * 100; 
    ratio[2] = (float)sum[2] / 48 * 100; 

    //Display the result!!!
    printf("Check Result\n");
    printf("Men: %d/%d (%.1f%%)\n", sum[0], 24,ratio[0]);
    printf("Women: %d/%d (%.1f%%)\n", sum[1], 24, ratio[1]);
    printf("Total: %d/%d (%.1f%%)\n", sum[2], 48, ratio[2]);
    return 0;
}
