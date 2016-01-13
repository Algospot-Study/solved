#include <iostream>

#define CLOCK_MAX 16
#define SWITCH_MAX 10
#define VALUE_MAX 4
#define INF 9999

using namespace std;

const int switchArr[10][5]{
        {0, 1,  2,  -1, -1},
        {3, 7,  9,  11, -1},
        {4, 10, 14, 15, -1},
        {0, 4,  5,  6,  7},
        {6, 7,  8,  10, 12},
        {0, 2,  14, 15, -1},
        {3, 14, 15, -1, -1},
        {4, 5,  7,  14, 15},
        {1, 2,  3,  4,  5},
        {3, 4,  5,  9,  13}
};

int inputClock[CLOCK_MAX];

bool isFinished() {
    for (int element : inputClock)
        if (element != 12) return false;
    return true;
}

void pressBtn(int switchBtn) {
    for (int clockNum : switchArr[switchBtn]) {
        inputClock[clockNum] += 3;
        if (inputClock[clockNum] >= 15) inputClock[clockNum] = 3;
    }
}

int getMin(int btnCount) {
    int ret = INF;
    if (btnCount == SWITCH_MAX) return isFinished() ? 0 : INF;
    for (int i = 0; i < VALUE_MAX; ++i) {
        ret = min(ret, i + getMin(btnCount + 1));
        pressBtn(btnCount);
    }
    return ret;
}

int main() {
    int testCase;
    cin >> testCase;
    while (testCase--) {
        for (int i = 0; i < CLOCK_MAX; ++i) {
            cin >> inputClock[i];
        }
        int min = getMin(0);
        if (min < INF) cout << min << endl;
        else cout << -1 << endl;
    }
}