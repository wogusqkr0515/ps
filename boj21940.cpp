#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
int INF = 0x3f3f3f3f;
int board[201][201];
vector<int> v, answer;

void sol() {
    int ans = 0x7f7f7f7f;

    for (int k=1;k<=N;k++) {
        for (int i=1;i<=N;i++) {
            for (int j=1;j<=N;j++) {
                if (i==j) board[i][j] = 0;
                else if (board[i][j] > board[i][k] + board[k][j]) board[i][j] = board[i][k] + board[k][j];
            }
        }
    }

    for (int i=1;i<=N;i++) {
        int maxIter = 0;
        for (int node : v) {
            int iter = 0;
            if (board[i][node] == INF || board[node][i] == INF) break;
            iter += (board[i][node] + board[node][i]);
            maxIter = max(maxIter, iter);
        }
        if (ans >= maxIter) {
            if (ans > maxIter) {
                ans = maxIter;
                answer.clear();
            }
            answer.push_back(i);
        }
    }

    for (int iter : answer)
        cout << iter << " ";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c;
    cin >> N >> M;
    fill(&board[1][1], &board[N][N], INF);

    for (int i=0;i<M;i++) {
        cin >> a >> b >> c;
        board[a][b] = c;
    }
    cin >> K;
    for (int i=0;i<K;i++) {
        cin >> a;
        v.push_back(a);
    }

    sol();
}