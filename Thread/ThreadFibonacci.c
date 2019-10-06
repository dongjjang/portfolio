#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

DWORD WINAPI ThreadFunc(LPVOID);
int destinationNum[1];

int main()
{
    HANDLE hThread;     // 스레드에 접근하기 위한 핸들
    DWORD threadID;
    int inputNum;
    int i;

    printf("부모 스레드를 실행합니다.\n");
    printf("피보나치 수열 계산을 위한 수를 입력해 주세요 : ");
    scanf("%d", &inputNum);

    hThread = CreateThread(NULL, 0, ThreadFunc, (LPVOID)i, 0, &threadID);

    if (hThread){
        printf("자식 스레드로 값을 넘깁니다.\n\n");
        destinationNum[0] = inputNum;
        CloseHandle(hThread);
    }
    if (!hThread){
        printf("자식스레드 생성에 실패하였습니다.");
    }
    Sleep(1000);                    // 자식 스레드가 종료되기까지 대기시켜줌
    printf("부모 스레드가 성공적으로 종료되었습니다.");

    return EXIT_SUCCESS;
}

DWORD WINAPI ThreadFunc(LPVOID n)
{
    int past = 0;			// 이전의 피보나치 수열 수
	int present = 1;		// 현재의 피보나치 수열 수
	int save = 0;			// 다음 연산을 위해 현재 수를 저장해두는 저장공간

    printf("자식 스레드가 실행되었습니다.\n");

	for (int i = 0; i < destinationNum[0] + 1; i++) {
		if (i == 0) {
			printf("0번째 피보나치 수열은 0입니다.\n");	
		}
		else if (i == 1) {
			printf("1번째 피보나치 수열은 1입니다.\n");
		}
		else {
			save = present;
			present = past + present;
			past = save;

			printf("%d번째 피보나치 수열은 %d입니다.\n", i, present);
		}
	}

    printf("자식 스레드가 종료되었습니다.\n\n");

	return 0;
}