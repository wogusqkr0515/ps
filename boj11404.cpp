#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int INF = 2e9;
int board[101][101];

void print() {
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            if (board[i][j] == INF) cout << "0 ";
            else cout << board[i][j] << " ";
        }
        cout << '\n';
    }
}

void sol() {
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            for (int k=1;k<=N;k++) {
                if (j==k) board[j][k] = 0;
                else {
                    if (i==k || i==j) continue;
                    if (board[j][i] == INF || board[i][k] == INF) continue;
                    if (board[j][k] > board[j][i] + board[i][k]) board[j][k] = board[j][i] + board[i][k];
                }
            }
        }
    }
    
    print();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c;
    cin >> N >> M;
    fill(&board[1][1], &board[N][N], INF);
    for (int i=0;i<M;i++) {
        cin >> a >> b >> c;
        board[a][b] = min(board[a][b], c);
    }

    sol();
}