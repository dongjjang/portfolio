#include <stdio.h>
#include <math.h>

int armercalc(int baseArmer, int itemArmer, int fairyStat, int collocation, int dollSkill, int fairySkill, int fairyChar);
double gohomenow(int num);
void fireStat(int fire);

// RoundDown = floor() , RoundUp = ceil()
int armercalc(int baseArmer, int itemArmer, int fairyStat, int collocation, int dollSkill, int fairySkill, int fairyChar)
{
    int num;

    num = floor(ceil((ceil(baseArmer) + itemArmer) * gohomenow(fairyStat)) * gohomenow(collocation) * gohomenow(dollSkill) * gohomenow(fairySkill) * gohomenow(fairyChar));

    return num;
}

double gohomenow(int num)
{
    double calc;

    calc = (num + 100) * 0.01;

    return calc;
}

void fireStat(int fire)
{
    int min;
    int max;

    min = ceil(fire * 0.85);
    max = ceil(fire * 1.15);

    printf("데미지 기댓값 %d ~ %d\n", min, max);
}

int main()
{
    int baseArmer;
    int itemArmer;
    int fairyStat;
    int collocation;
    int dollSkill;
    int fairySkill;
    int fairyChar;

    int result;

    int judge1 = 30;
    int judge2 = 42;
    int judge3 = 50;
    int judge4 = 45;
    int judge5 = 58;
    int judge6 = 55;

    printf("인형 장갑 계산기\n\n");

    printf("인형의 장갑(정수) : ");
    scanf("%d", &baseArmer);
    printf("장비 능력치(정수) : ");
    scanf("%d", &itemArmer);
    printf("요정의 스탯(%%) : ");
    scanf("%d", &fairyStat);
    printf("진형 버프(%%) : ");
    scanf("%d", &collocation);
    printf("인형의 스킬(%%) : ");
    scanf("%d", &dollSkill);
    printf("요정 스킬(%%) : ");
    scanf("%d", &fairySkill);
    printf("요정 특성(%%) : ");
    scanf("%d", &fairyChar);

    result = armercalc(baseArmer, itemArmer, fairyStat, collocation, dollSkill, fairySkill, fairyChar);

    printf("장갑 계산 결과 : %d\n\n", result);

    printf("9-6 포위돌파, 이성질체 소란 속에서 II(노멀) = 화력 %d\n", judge1);
    fireStat(judge1);
    printf("9-4E 매와 개 IV = 화력 %d\n", judge2);
    fireStat(judge2);
    printf("10-6 목숨을 건 돌파 = 화력 %d\n", judge3);
    fireStat(judge3);
    printf("특이점 말벌집 = 화력 %d\n", judge4);
    fireStat(judge4);
    printf("이성질체 소란 속에서 II(하드) = 화력 %d\n", judge5);
    fireStat(judge5);
    printf("9-4N 무지개 다리 IV = 화력 %d\n", judge6);
    fireStat(judge6);

    return 0;
}