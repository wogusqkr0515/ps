#include <iostream>

using namespace std;
typedef long long ll;

ll dp[100][100];
int N, board[100][100];
int dx[2] = {1,0};
int dy[2] = {0,1};

ll sol(int r, int c) {
    if (r == N-1 && c == N-1) return 1;

    if (dp[r][c] != -1) return dp[r][c];

    ll &ret = dp[r][c];
    ret = 0;
    if (!board[r][c]) return 0;

    for (int i=0;i<2;i++) {
        int nr=r,nc=c;
        for (int j=0;j<board[r][c];j++) {
            nr += dy[i]; nc += dx[i];
        }
        
        if (!(nr>=0 && nc>=0 && nr<N && nc<N)) continue;
        ret += sol(nr, nc);
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            cin >> board[i][j];
            dp[i][j] = -1;
        }
    }

    cout << sol(0, 0);
}