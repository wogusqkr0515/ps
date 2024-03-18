#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int R, C;
int board[1000][1000];
int board2[1000][1000];

bool check(int r, int c) {
    if (board[r][c] == 0) return false;
    if (board[r-1][c] == 0) return false;
    if (board[r][c-1] == 0) return false;
    if (board[r-1][c-1] == 0) return false;

    return true;
}

int getN (int r, int c) {
    int ret = 10000;
    ret = min(ret, board2[r-1][c]);
    ret = min(ret, board2[r][c-1]);
    ret = min(ret, board2[r-1][c-1]);
    return ret;
}

void dp() {
    int ans;
    if (R==1 || C==1) {
        ans = 0;
        for (int i=0;i<R;i++) {
            for (int j=0;j<C;j++) {
                ans = max(ans, board[i][j]);
            }
        }
        cout << ans;
        return;
    }
    ans = 0;
    for (int i=1;i<R;i++) {
        ans = max(ans, board2[i][0]);
        for (int j=1;j<C;j++) {
            if (check(i, j)) board2[i][j] = getN(i, j) + 1;
            ans = max(ans, board2[i][j]);
        }
    }

    cout << (ans*ans);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string num;
    cin >> R >> C;
    for (int i=0;i<R;i++) {
        cin >> num;
        for (int j=0;j<C;j++) {
            if (num[j] == '1') board[i][j] = 1;
            else board[i][j] = 0;
            board2[i][j] = board[i][j];
        }
    }

    dp();
}