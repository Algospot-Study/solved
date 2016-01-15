#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>

using namespace std;

int slice[4][2][2] = { // num, Á¶°¢, dy/dx
    {    {1, 0}, {0, 1}        },
    {   {1, 0}, {1, -1} },
    {   {1, 0}, {1, 1} },
    {   {0, 1}, {1, 1} }
};

int h, w;

void put(vector<vector<char>> &board, int num, int y, int x) {
    int ny[2], nx[2];
    for (int i = 0; i < 2; ++i) {
        ny[i] = y + slice[num][i][0];
        nx[i] = x + slice[num][i][1];

        board[ny[i]][nx[i]] = '#';
    }
    board[y][x] = '#';
}

void unput(vector<vector<char>> &board, int num, int y, int x) {
    int ny[2], nx[2];
    for (int i = 0; i < 2; ++i) {
        ny[i] = y + slice[num][i][0];
        nx[i] = x + slice[num][i][1];

        board[ny[i]][nx[i]] = '.';
    }
    board[y][x] = '.';
}

int fill(vector<vector<char>> &board) {
    int ret = 0;

    bool isFull = true;

    int y, x;

    for (int i = 0; i < h + 2; ++i) {
        for (int j = 0; j < w + 2; ++j) {
            if (board[i][j] == '.') {
                y = i, x = j;
                isFull = false;
                break;
            }
        }
        if (isFull == false) {
            break;
        }
    }

    if (isFull == true) {
        return 1;
    }

    for (int i = 0; i < 4; i++) {
        int ny1 = y + slice[i][0][0];
        int nx1 = x + slice[i][0][1];
        int ny2 = y + slice[i][1][0];
        int nx2 = x + slice[i][1][1];

        if ( board[ny1][nx1] == '.' && board[ny2][nx2] == '.') {
            put(board, i, y, x);
            ret += fill(board);
            unput(board, i, y, x);
        }
    }

    return ret;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> h >> w;

        vector<vector<char>> board(h+2, vector<char>(w+2, '#'));

        for (int i = 1; i <= h; ++i) {
            getchar();
            for (int j = 1; j <= w; ++j) {
                board[i][j] = getchar();
            }
        }

        cout << fill(board) << endl;
    }
    return 0;
}