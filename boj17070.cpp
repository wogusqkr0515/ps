#include <iostream>
#include <algorithm>

using namespace std;

int N, ans=0;
int board[20][20];

// dir 가로 - 0, 세로 - 1, 대각선 - 2 
void dfs(int row, int col, int dir) {
    if (row==N || col==N) return;
    if (row == N-1 && col == N-1) {
        ans++;
        return;
    }
    if (dir != 1 && board[row][col+1] == 0) dfs(row, col+1, 0); 
    if (dir != 0 && board[row+1][col] == 0) dfs(row+1, col, 1);
    if (board[row][col+1] + board[row+1][col] + board[row+1][col+1] >= 1) return;
    dfs(row+1, col+1, 2);
}

void sol() {
    if (board[0][2] == 0)
        dfs(0, 2, 0);
    if (board[0][2] + board[1][1] + board[1][2] == 0)
        dfs(1, 2, 2);

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=0;i<N;i++) 
        for (int j=0;j<N;j++)
            cin >> board[i][j];

    sol();
}