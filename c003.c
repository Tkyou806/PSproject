/*
Programming Studio C003
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findRoom( 
    int persons[5]); // 5개의 호실 중 빈 베드가 있는 방을 찾아낸다. (리턴값 1~5)

void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20],
                 int wr[10], int wc); // 배정 결과를 출력한다.

int main()
{
  char mnames[10][20];        // 남학생명단(최대 10명)
  int mroom[10];              // 남학생명단별 호실 배정 목록
  char wnames[10][20];        // 여학생명단(최대 10명)
  int wroom[10];              // 여학생명단별 호실 배정 목록
  int person[2][5] = {0};     // 2개 층별 5개 호실의 배정 인원 수
  int mcount = 0, wcount = 0; // 인원 합계 (남, 여)
  int menu;

  srand(time(0));
  printf("===========================================\n");
  printf("생활관 호실 배정 프로그램\n");
  printf("===========================================\n");
  while (1)
  {
    printf("메뉴 : 1.남학생 등록 2.여학생 등록 0.종료 > ");
    scanf("%d", &menu);
    if (menu == 0)
      break;
    else if (menu == 1)
    {
      if (mcount >= 10)
      {
        printf("정원 초과입니다. 등록불가!\n");
        continue;
      }
      printf("학생 이름은? > ");
      scanf("%s", mnames[mcount]);
      int roomno = findRoom(person[0]);
      mroom[mcount] = 100 + roomno;
      printf("%s 학생 %d호실 배정되었습니다.\n", mnames[mcount], mroom[mcount]);
      mcount++;
    }
    else if (menu == 2)
    {
      if (wcount >= 10)
      {
        printf("정원 초과입니다. 등록불가!\n");
        continue;
      }
      printf("학생 이름은? > ");
      scanf("%s", wnames[wcount]);
      int roomno = findRoom(person[1]);
      wroom[wcount] = 200 + roomno;
      printf("%s 학생 %d호실 배정되었습니다.\n", wnames[wcount], wroom[wcount]);
      wcount++;
    }
  }

  printf("===========================================\n");
  printf("생활관 호실 배정 결과는 다음과 같습니다.\n");
  printf("===========================================\n");
  printReport(mnames, mroom, mcount, wnames, wroom, wcount);

  return 0;
}

int findRoom(int persons[5])
{
  // main에서 persons[0]이나 persons[1]을 받아오기 때문에 각 층을 나타내며 각 방을
  // 확인하는 코드가 필요하다.==> 반복문
  // 랜덤해야 하므로 rand() 사용하여 방을 선정한다.
  // 2명이 넘어가면 안 되므로 조건문 if를 이용한다.

  int i = 0;
  
   while (1){
    i = rand() % 5;
    if (persons[i] < 2)
    {
      persons[i]++;
      break;
    }

  };
  return i + 1;
}

void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc)
{
  // 남학생
  printf("남학생 명단 (%d명)\n", mc);
  for (int i = 0; i < mc; i++)
  {
    printf("%d. %s [%d]호\n", i + 1, mn[i], mr[i]);
  }
  printf("\n");
  // 여학생
  printf("여학생 명단 (%d명)\n", wc);
  for (int i = 0; i < wc; i++)
  {
    printf("%d. %s [%d]호\n", i + 1, wn[i], wr[i]);
  }
  printf("\n");
  
  // 호실별 배정 명단
  //방을 순서대로 표현하고 그에 해당하는 학생을 최대 2명까지 표시해야 하므로 조건문 이용한다.
  printf("호실별 배정 명단\n");
  for (int i = 0; i < 2; i++)
  {//남학생
    if (i == 0)
    {
      for (int j = 0; j < 5; j++)
      {
        //호실
        printf("%d0%d : ", i + 1, j + 1);
        for (int k = 0; k < 10; k++)
        {//각각 남학생의 호수와 지금 찍히는 호수가 같은지 비교 후 같다면 프린트한다.
          if (mr[k] == (i + 1) * 100 + (j + 1))
          {
            printf("%s ", mn[k]);
          }
        }
        printf("\n");
      }  
    }//여학생
    else if (i == 1) 
    {
      for (int j = 0; j < 5; j++)
      {
        //호실
        printf("%d0%d : ", i + 1, j + 1);
        for (int k = 0; k < 10; k++)
        {
          //각각 여학생의 호수와 지금 찍히는 호수가 같은지 비교 후 같다면 프린트한다.
          if (wr[k] == (i + 1) * 100 + (j + 1))
          {
            printf("%s ", wn[k]);
          }
        }
        printf("\n");
      }
    }
  }
}

