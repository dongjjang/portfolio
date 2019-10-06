#include <iostream>
#include "ExpectedValue.h"
#include "FireClac.h"

using namespace std;

int main()
{
    FireClac fireclac;
    ExpectedValue value;

    int baseFire;
    int loveBonus;
    int itemFire;
    int fairyStat;
    int collocation;
    int dollSkill;
    int fairySkill;
    int fairyChar;

    int result;

    cout << "인형 화력 계산기" << endl << endl;

    cout << "인형의 화력(정수) : ";
    cin >> baseFire;
    cout << "인형의 호감도 보너스(%%) : ";
    cin >> loveBonus;
    cout << "장비 능력치(정수) : ";
    cin >> itemFire;
    cout << "요정의 스탯(%%) : ";
    cin >> fairyStat;
    cout << "진형 버프(%%) : ";
    cin >> collocation;
    cout << "인형 스킬(%%) : ";
    cin >> dollSkill;
    cout << "요정 스킬(%%) : ";
    cin >> fairySkill;
    cout << "요정 특성(%%) : ";
    cin >> fairyChar;

    result = fireclac.fireCalc(baseFire, loveBonus, itemFire, fairyStat, collocation, dollSkill, fairySkill, fairyChar);

    value.fireStat(result);

    return 0;
}