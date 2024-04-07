#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define r first
#define c second

int N, M;
int board[100][100], board2[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool isvisit[100][100];
bool flag = false;


void sol() {
    int ans = 0;
    while (flag) {
        fill(&isvisit[0][0], &isvisit[N][M], false);
        fill(&board2[0][0], &board2[N][M], 0);

        queue<pair<int,int>> q, melt;
        q.push({0,0});
        isvisit[0][0] = true;
        flag = false;

        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            for (int i=0;i<4;i++) {
                int nr, nc;
                nr = cur.r+dy[i]; nc = cur.c+dx[i];
                if (nr>=0 && nc>=0 && nr<N && nc<M) {
                    if (!isvisit[nr][nc] && board[nr][nc] == 0) {
                        isvisit[nr][nc] = true;
                        q.push({nr, nc});
                    }
                    if (board[nr][nc] == 1) board2[nr][nc]++;
                    if (board2[nr][nc] >= 2 && !isvisit[nr][nc]) {
                        melt.push({nr, nc});
                        isvisit[nr][nc] = true;
                    }
                }
            }
        }
        if (!melt.empty()) { ans++; flag = true; }
        while (!melt.empty()) {
            auto cur = melt.front(); melt.pop();
            board[cur.r][cur.c] = 0;
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
            if (board[i][j] == 1) flag = true;
        }
    }
    
    sol();
}