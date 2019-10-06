/*
	컴퓨터소프트웨어공학과 20153265 김동현
	2019.03.29
	CreateProcess() 함수를 사용하여 피보나치 프로세스를 생성하여 실행하는 부모 프로세스
*/

#include <Windows.h>
#include <stdio.h>

int main()
{
	int wantNum = 0; // 검색을 원하는 피보나치 수열 번호

	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	printf("부모 프로세스가 실행되었습니다.\n\n");
	printf("피보나치 수열 번호를 입력 해 주세요 : ");
	scanf("%d", &wantNum);
	printf("\n");

	// 음의 정수를 전달하지 않도록 하는 while 조건문
	while (wantNum < 0)
	{
		printf("음의 정수는 계산이 불가능합니다.\n");
		printf("다시 입력 해 주세요 : ");
		scanf("%d", &wantNum);
		printf("\n");
	}

	char fibNum[30]; // 입력받은 값을 문자열 형태로 변환하기 위한 배열

	/* wantNum를 %d = 정수형에서 fibNum 문자열로 변환
	다른 방식으로 #include <stdlib.h> 선언 후 fibNum = _itoa(wantNum)으로 해도 가능하다.*/
	sprintf(fibNum, "%d", wantNum);

	char root[] = "Fibonacci.exe "; // fibonacci.exe를 실행. 루트를 적어주지 않으면 우선 같은파일에서 탐색함. 한칸 띄우는 이유는 띄워진 칸에 fibNum을 붙여서 인수로 넘기기 위함임.

	/* 문자열을 합쳐주는 함수. runFile에 fibnum이 뒤로가서 붙게 됨. */
	strcat(root, fibNum);

	// 메모리 할당
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	// 자식 프로세스 실행 부분
	if (!CreateProcess(NULL, root, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		// 프로세스 생성 시 오류가 있다면 프로세스를 실패했다고 띄우고 종료시킴
		fprintf(stderr, "프로세스 생성 실패!");
		return -1;
	}

	// 부모 프로세스가 자식 프로세스가 끝나기를 기다림
	WaitForSingleObject(pi.hProcess, INFINITE);
	printf("\n자식 프로세스 성공!\n");

	//핸들 닫기
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}