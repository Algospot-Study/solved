#include <iostream>
#include <vector>

using namespace std;

vector<bool> isFinished;
vector<vector<bool>> areFriend;

int n;

bool isComplete(vector<bool> &isFinished){
    for(bool element : isFinished)
        if(!element) return false;
    return true;
}

int getMate(vector<bool> &isFinished, int startFlag){
    int ret = 0;
    //기저사례
    if(isComplete(isFinished)) return 1;
    for(int i=startFlag; i<n; ++i){
        if(isFinished[i] == false){
            for(int j=i+1; j<n; ++j){
                if(areFriend[i][j] && !isFinished[j]){
                    isFinished[i] = isFinished[j] = true;
                    ret += getMate(isFinished, i+1);
                    //재귀로 넘긴 후 다시 돌아야하므로 isFinished를 false로 다시 초기화
                    isFinished[i] = isFinished[j] = false;
                }
            }
        }
    }
    return ret;
}

int main(){
    int testCase;
    cin >> testCase;
    while (testCase --) {
        int m;
        cin >> n >>m;
        areFriend = vector<vector<bool>>(n, vector<bool>(n, false));
        for(int j=0; j<m; ++j){
            int friendA, friendB;
            cin >> friendA >> friendB;
            areFriend[friendA][friendB] = areFriend[friendB][friendA] = true;
        }
        isFinished = vector<bool>(n, false);
        cout << getMate(isFinished, 0) << endl;
    }
}