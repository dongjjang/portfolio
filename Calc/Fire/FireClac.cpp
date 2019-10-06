#include "FireClac.h"
#include "Percent.h"

// rounddown => floor(), roundup=> ceil()
int FireClac::fireCalc(int baseFire, int loveBonus, int itemFire, int fairyStat, int collocation, int dollSkill, int fairySkill, int fairyChar)
{
    int num;
    Percent p;

    num = ceil(ceil((ceil(baseFire * p.percent(loveBonus)) + itemFire) * p.percent(fairyStat)) * p.percent(collocation) * p.percent(dollSkill) * p.percent(fairySkill) * p.percent(fairyChar));

    return num;
}