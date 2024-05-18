#include <iostream>
#include <algorithm>

using namespace std;

int N,M,board[500][500], ans=0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool chk[500][500];

void dfs(int r, int c, int depth, int sum) {
    if (depth == 4) {
        ans = max(ans, sum);
        return;
    }

    for (int i=0;i<4;i++) {
        int nr, nc;
        nr = r + dy[i]; nc = c + dx[i];
        if (!(nr>=0 && nc>=0 && nr<N && nc<M)) continue;
        if (chk[nr][nc]) continue;
        chk[nr][nc] = true;
        dfs(nr, nc, depth+1, sum + board[nr][nc]);
        chk[nr][nc] = false;
    }
}

void sub(int r, int c) {
    int sum;

    if (c<M-2) {
        sum = 0;
        for (int i=0;i<3;i++) {
            sum += board[r][c+i];
        }
        if (r>0) {
            ans = max(ans, sum + board[r-1][c+1]);
        }
        if (r<N-1) {
            ans = max(ans, sum + board[r+1][c+1]);
        }
    }
    if (r<N-2) {
        sum = 0;
        for (int i=0;i<3;i++) {
            sum += board[r+i][c];
        }
        if (c>0) {
            ans = max(ans, sum + board[r+1][c-1]);
        }
        if (c<M-1) {
            ans = max(ans, sum + board[r+1][c+1]);
        }
    }
}

void sol() {
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            chk[i][j] = true;
            dfs(i,j,1, board[i][j]);
            sub(i,j);
            chk[i][j] = false;
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            cin >> board[i][j];
        }
    }

    sol();
}