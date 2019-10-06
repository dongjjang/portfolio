#include <iostream>
#include "ExpectedValue.h"

using namespace std;

void ExpectedValue::fireStat(int fire) {
    int min;
    int max;

    min = ceil(fire * 0.85);
    max = ceil(fire * 1.15);

    cout << "데미지 기댓값 " << min << " ~ " << max << endl;
}