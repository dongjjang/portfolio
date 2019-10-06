/*
	컴퓨터소프트웨어공학과 20153265 김동현
	2019.03.29
	피보나치 수열을 계산하는 프로그램
*/

#include <stdio.h>
#include <Windows.h>
#include <tchar.h>

int main(int argc, char *argv[]) {

	// DWORD 자료형은 char과 흡사한 자료형으로 atoi 대신 ttoi사용 위하여 씀 받은 문자열을 정수로 변경
	// argv[]는 앞에서 넘어온 인수의 뒤에 스페이스바로 구분하여 인수를 받아들임. 배열0번은 실행프로그램 이름임
	DWORD recieveNum = _ttoi(argv[1]);

	int destinationNum = recieveNum;	// int형에 받은 번호를 매핑

	int past = 0;			// 이전의 피보나치 수열 수
	int present = 1;		// 현재의 피보나치 수열 수
	int save = 0;			// 다음 연산을 위해 현재 수를 저장해두는 저장공간

	for (int i = 0; i <= destinationNum; i++) {
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

	return 0;
}