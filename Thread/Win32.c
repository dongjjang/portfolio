#include <stdio.h>
#include <windows.h>

DWORD num;      // 스레드 간 공유되는 증가 감소 값
DWORD WINAPI Thread_producer(LPVOID);
DWORD WINAPI Thread_consumer(LPVOID);

int main()
{
    HANDLE ThreadHandle[2];
    DWORD threadID;
    int param = 0;
    
    ThreadHandle[0] = CreateThread(NULL, 0, Thread_producer, (LPVOID)param, 0, &threadID);
    ThreadHandle[1] = CreateThread(NULL, 0, Thread_consumer, (LPVOID)param, 0, &threadID);

    for(int i=0; i<2; i++) {
        if(ThreadHandle[i] != NULL) {
            WaitForSingleObject(ThreadHandle[i], INFINITE);  // 스레드 종료까지 대기
            CloseHandle(ThreadHandle[i]);      // 핸들을 닫음
        }
    }
    if (num == 0) {
        printf("남은 데이터가 없습니다.");
    }
    else {
        printf("남은 데이터가 있습니다.");
    }
    return 0;
}

/* 생산자 스레드 */
DWORD WINAPI Thread_producer(LPVOID Param)
{
    for(int i=0; i<10; i++) {
        num++;
        if (num == 1) {
            printf("데이터 생산됨\n");
        }
        Sleep(5);
    }
}

/* 소비자 스레드 */
DWORD WINAPI Thread_consumer(LPVOID Param)
{
    for(int i=0; i<10; i++) {
        num--;
        if (num == 0) {
            printf("데이터 사용됨\n");
        }
        Sleep(5);
    }
}

