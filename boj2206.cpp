#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

struct Coord {
    int r, c, s;
    bool w;
    Coord(int row, int col, int step, bool isMeetWall): r(row), c(col), s(step), w(isMeetWall) {};
};

int N, M, mind;
int INF = 2e9;
int board[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool isvisit[1002][1002];
bool isvisit2[1002][1002];

void bfs() {
    queue<Coord> q;
    q.push(Coord(0, 0, 1, false));
    isvisit[0][0] = true;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        if (cur.r == N-1 && cur.c == M-1) mind = min(mind, cur.s);

        for (int i=0;i<4;i++) {
            int nr, nc;
            nr = cur.r + dy[i]; nc = cur.c + dx[i];
    
            if (nr>=0 && nc>=0 && nr<N && nc<M) {
                if (board[nr][nc] == 0) {
                    if (!isvisit[nr][nc] && !cur.w) {
                        isvisit[nr][nc] = true;
                        q.push(Coord(nr, nc, cur.s+1, false));
                    }
                    else if (!isvisit2[nr][nc] && cur.w) {
                        isvisit2[nr][nc] = true;
                        q.push(Coord(nr, nc, cur.s+1, true));
                    }
                }
                else if (!isvisit2[nr][nc] && !cur.w) {
                    isvisit2[nr][nc] = true;
                    q.push(Coord(nr, nc, cur.s+1, true));
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> N >> M;
    for (int i=0;i<N;i++) {
        cin >> str;
        for (int j=0;j<M;j++) {
            board[i][j] = str[j]-'0';
        }
    }
    
    mind = INF;
    fill(&isvisit[0][0], &isvisit[N][M], false);
    fill(&isvisit2[0][0], &isvisit2[N][M], false);
    bfs();

    if (mind == INF) cout << -1;
    else cout << mind;
}