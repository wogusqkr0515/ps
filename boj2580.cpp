#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int cnt = 0;
int board[9][9], board2[9][9];
bool chk1[9][10], chk2[9][10], chk3[9][10];
vector<pair<int,int>> v;
bool flag = false;

int square(int i, int j) {
    return (i/3)*3 + (j/3);
}

void dfs(int idx) {
    if (idx == cnt) {
        for (int i=0;i<9;i++) {
            for (int j=0;j<9;j++) 
                cout << board[i][j] << " ";
            cout << '\n';
        }
        flag = true;
        return;
    }

    if (flag) return;

    int i = v[idx].X, j = v[idx].Y;
    for (int z=1;z<=9;z++) {
        if (!chk1[i][z] && !chk2[j][z] && !chk3[square(i,j)][z]) {
            board[i][j] = z;
            chk1[i][z] = true;
            chk2[j][z] = true;
            chk3[square(i,j)][z] = true;
            dfs(idx+1);
            if (flag) return;
            board[i][j] = 0;
            chk1[i][z] = false;
            chk2[j][z] = false;
            chk3[square(i,j)][z] = false;
        }
    }
}

void sol() {
    cnt = v.size();
    dfs(0);    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(chk1, false, sizeof(chk1));
    memset(chk2, false, sizeof(chk2));
    memset(chk3, false, sizeof(chk3));

    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            cin >> board[i][j];
            if (board[i][j] > 0) {
                chk1[i][board[i][j]] = true;
                chk2[j][board[i][j]] = true;
                chk3[square(i,j)][board[i][j]] = true;
            } else v.push_back({i,j});
        }
    }

    sol();
}