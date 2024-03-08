/*
4층 짜리  3생활관의 각 층에는  , 4개씩 호실이 있고 각 호실은 모두 4인실이다 즉 총 48명이 입주해 있다
1, 2층은 남학생용 호실이고  , 3, 4 층은 여학생용 호실이다
다음과 같이 각 호실별로 점호 인원을 입력받아 저장한 후에 다음과 같은 정보를 계산하여 출력하라 , .
1) , 점호를 받은 남학생 수 전체 남학생 수에 대한 비율
2) , 점호를 받은 여학생 수 전체 여학생 수에 대한 비율
3) , 점호를 받은 모든 학생 수 전체 인원 수에 대한 비율
* 변수 사용
int person[4][3]; // 4 3 개 층별 개 호실의 점호 인원 수
int sum[3]; // ( , , ) 점호 인원 수 합계 남 여 전체
float ratio[3]; // ( , , ) 점호 인원 수 비율 남 여 전체
int i, j; // 반복문을 위한 변수
*/
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
     
    sum[2] = sum[0] + sum[1]; 
    
    ratio[0] = (float)sum[0] / 24 * 100;
    ratio[1] = (float)sum[1] / 24 * 100; 
    ratio[2] = (float)sum[2] / 48 * 100; 


    printf("Check Result\n");
    printf("Men: %d/%d (%.1f%%)\n", sum[0], 24,ratio[0]);
    printf("Women: %d/%d (%.1f%%)\n", sum[1], 24, ratio[1]);
    printf("Total: %d/%d (%.1f%%)\n", sum[2], 48, ratio[2]);
    return 0;
}
