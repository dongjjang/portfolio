/*
	컴퓨터소프트웨어공학과 20153265 김동현
	2019.03.29
	fork() 함수를 사용하여 피보나치 프로세스를 생성하여 실행하는 부모 프로세스
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int destinationNum = 0; // 원하는 피보나치 수열까지의 번호

    printf("부모 프로세스가 실행되었습니다.\n\n");
    printf("피보나치 수열 번호를 입력 해 주세요 : ");
    scanf("%d", &destinationNum);
    printf("\n");

    // 음의 정수를 전달하지 않도록 하는 while 조건문
    while (destinationNum < 0)
    {
        printf("음의 정수는 계산이 불가능합니다.\n");
        printf("다시 입력 해 주세요 : ");
        scanf("%d", &destinationNum);
        printf("\n");
    }

    pid_t pid;    // 사실 int와 동일 그냥 pid_t라는 자료형이 존재함
    pid = fork(); // 프로세스 생성 실패일 경우 -1을 리턴 성공시 0을 리턴함

    int past = 0;    // 이전의 피보나치 수열 수
    int present = 1; // 현재의 피보나치 수열 수
    int save = 0;    // 다음 연산을 위해 현재 수를 저장해두는 저장공간

    if (pid < 0)
    {
        printf("프로세스 생성 에러\n\n");
        return -1;
    }
    else if (pid == 0)
    {
        for (int i = 0; i <= destinationNum; i++)
        {

            if (i == 0)
            {
                printf("0번째 피보나치 수열은 0입니다.\n");
            }
            else if (i == 1)
            {
                printf("1번째 피보나치 수열은 1입니다.\n");
            }
            else
            {
                save = present;
                present = past + present;
                past = save;

                printf("%d번째 피보나치 수열은 %d입니다.\n", i, present);
            }
        }
    }
    else
    {
        wait(NULL);     // wait를 부르지 않으면 프로세스에 문제가 생김
        printf("\n자식 프로세스 성공!\n\n");
    }
}