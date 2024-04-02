#include <iostream>
#include <algorithm>

using namespace std;


int T, N, M, W;
int INF = 0x3f3f3f3f;
int board[502][502];

void sol() {
    for (int k=1;k<=N;k++) {
        for (int i=1;i<=N;i++) {
            for (int j=1;j<=N;j++) {
                if (i==j) board[i][j] = 0;
                else if (board[i][j] > board[i][k] + board[k][j]) board[i][j] = board[i][k] + board[k][j];
            }
        }
    }

    for (int i=1;i<N;i++) {
        for (int j=i+1;j<=N;j++) {
            if (board[i][j] + board[j][i] < 0) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
    return;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c;
    bool flag;
    cin >> T;

    for (int i=0;i<T;i++) {
        cin >> N >> M >> W;
        fill(&board[1][1], &board[N+1][N+1], INF);

        for (int j=0;j<M;j++) {
            cin >> a >> b >> c;
            board[a][b] = min(board[a][b], c);
            board[b][a] = min(board[b][a], c);
        }
        flag = false;
        for (int j=0;j<W;j++) {
            cin >> a >> b >> c;
            if (a==b) flag = true;
            board[a][b] = c * -1;
        }
        
        if (flag) cout << "YES\n";
        else sol();
    }
}