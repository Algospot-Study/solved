#include <iostream>
#include <algorithm>
#include <vector>

#define clockState_MAX 16
#define INF 987654321

using namespace std;


int clockState[clockState_MAX];

//get min value
int f(int sw[][5], int depth){
    int ret = INF;
    if (depth == 10) {
        for (int i = 0; i < clockState_MAX; i++) {
            if (clockState[i] != 0) return INF;
        }
        return 0;
    }
    int mine;
    for (mine = 0; mine < 4; mine++){
        for (int j = 0; j < 5 && sw[depth][j] != -1; j++) {
            clockState[sw[depth][j]] += mine;
            clockState[sw[depth][j]] %= 4;
        }
        
        ret = min(ret, f(sw, depth + 1) + mine);

        for (int j = 0; j < 5 && sw[depth][j] != -1; j++) {
            clockState[sw[depth][j]] -= mine;
            clockState[sw[depth][j]] %= 4;
        }

    }
    return ret;
}

int main() {
    int t;
    cin >> t;

    int sw[10][5] = { { 0, 1, 2, -1,-1 },
    { 3, 7, 9, 11, -1},
    {    4, 10, 14, 15 , -1},
  {  0, 4, 5, 6, 7},
  {  6, 7, 8, 10, 12},
  {  0, 2, 14, 15, -1},
   { 3, 14, 15, -1, -1},
   { 4, 5, 7, 14, 15},
   { 1, 2, 3, 4, 5},
   { 3, 4, 5, 9, 13}
    };

    while (t--) {
        for (int i = 0; i < clockState_MAX; ++i) {
            int a;
            cin >> a;
            clockState[i] = a / 3 % 4;
        }
        int ret = f(sw, 0);
        if (ret == INF)
            ret = -1;
        cout << ret << endl;

    }

    return 0;
}