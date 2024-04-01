#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int INF = 0x3f3f3f3f;
int board[101][101], nxt[101][101];

void print() {
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            if (board[i][j] == INF) cout << "0 ";
            else cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {\
            if (i==j) cout << "0\n";
            else if (board[i][j] == INF) cout << "0\n";
            else {
                int cnt= 1, idx = i;
                vector<int> v;
                v.push_back(i);
                while (idx!=j) {
                    cnt++;
                    idx = nxt[idx][j];
                    v.push_back(idx);
                }
                cout << cnt << " ";
                for (int iter : v) cout << iter << ' ';
                cout << '\n';
            }
        }
   }
}

void sol() {
    for (int k=1;k<=N;k++) {
        for (int i=1;i<=N;i++) {
            for (int j=1;j<=N;j++) {
                if (i==j) { board[i][j] = 0; nxt[i][j] = i; }
                else {
                    if (board[i][j] > board[i][k] + board[k][j]) {
                        board[i][j] = board[i][k] + board[k][j];
                        nxt[i][j] = nxt[i][k];
                    } 
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
        if (board[a][b] > c) {
            board[a][b] = c;
            nxt[a][b] = b;
        }
    }

    sol();
}