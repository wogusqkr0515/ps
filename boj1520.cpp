#include <iostream>
#include <algorithm>

using namespace std;

int N, M, ans=0;
int board[500][500], dp[500][500];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int dfs(int r, int c) {
    if (dp[r][c] != -1) return dp[r][c];
    if (r == N-1 && c == M-1) return 1;
    int &ret = dp[r][c];
    ret = 0; 

    for (int i=0;i<4;i++) {
        int nr,nc;
        nr = r+dy[i]; nc = c+dx[i];
        if (!(nr>=0 && nc>=0 && nr<N && nc<M)) continue;
        if (board[nr][nc] >= board[r][c]) continue;
        ret += dfs(nr, nc);
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            cin >> board[i][j];
            dp[i][j] = -1;
        }
    }

    cout << dfs(0,0);
}