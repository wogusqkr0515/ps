#include <iostream>
#include <algorithm>

using namespace std;

int N, M, R;
int INF = 0x3f3f3f3f;
int items[101], board[101][101];

void sol() {
    int ans = 0;
    for (int k=1;k<=N;k++) {
        for (int i=1;i<=N;i++) {
            for (int j=1;j<=N;j++) {
                if (i==j) board[i][j] = 0;
                else if (board[i][j] > board[i][k] + board[k][j]) board[i][j] = board[i][k] + board[k][j];
            }
        }
    }

    for (int i=1;i<=N;i++) {
        int cnt = 0;
        for (int j=1;j<=N;j++) {
            if (board[i][j] <= M) cnt += items[j];
        }
        ans = max(ans, cnt);
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c;
    cin >> N >> M >> R;
    for (int i=1;i<=N;i++) cin >> items[i];
    
    fill(&board[1][1], &board[N][N], INF);

    for (int i=0;i<R;i++) {
        cin >> a >> b >> c;
        board[a][b] = c;
        board[b][a] = c;
    }

    sol();
}