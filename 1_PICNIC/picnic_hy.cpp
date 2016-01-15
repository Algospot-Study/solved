#include <iostream>
#include <vector>

using namespace std;

vector<bool> isFinished;
vector<vector<bool>> isFriend;
int n;

bool isDone(vector<bool> &isFinished) {
    for (bool i : isFinished) {
        if (i == false) {
            return false;
        }
    }
    return true;
}

int mate(vector<bool> &isFinished, int startFlag) {
    int ret = 0;
    if (isDone(isFinished)) return 1;
    for (int i = startFlag; i < n; i++) {
        if (isFinished[i] == false) {
            for (int j = i + 1; j < n; ++j) {
                if ((isFriend[i][j]) && (!isFinished[j])) {
                    isFinished[i] = true;
                    isFinished[j] = true;
                    ret += mate(isFinished, i + 1);
                    isFinished[i] = false;
                    isFinished[j] = false;
                }
            }
        }
    }
    return ret;
}

int main() {
    int c;
    cin >> c;
    for (int i = 0; i < c; ++i) {
        int m;
        cin >> n >> m;

        isFriend = vector<vector<bool>>(n, vector<bool>(n, false));

        for (int j = 0; j < m; ++j) {
            int a, b;
            cin >> a >> b;

            isFriend[a][b] = true;
            isFriend[b][a] = true;
        }

        isFinished = vector<bool>(n, false);

        cout << mate(isFinished, 0) << endl;
    }

    return 0;
}