#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, board[101][101], board2[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool oob(int r, int c) {
    return !(r>=0 && c>=0 && r<N && c<N);
}

void bfs(int r, int c, int n) {
    queue<pair<int,int>> q;
    q.push({r,c});
    board2[r][c] = n;

    while (!q.empty()) {
        int cr, cc;
        tie(cr, cc) = q.front(); q.pop();

        for (int i=0;i<4;i++) {
            int nr, nc;
            nr = cr + dy[i]; nc = cc + dx[i];
            if (oob(nr,nc)) continue;
            if (board[nr][nc] && !board2[nr][nc]) {
                board2[nr][nc] = n;
                q.push({nr,nc});
            }
        }
    }
}

void dist() {
    queue<pair<int,int>> q;
    int ans = 2e9;

    fill(&board[0][0], &board[101][0], -1);

    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            if (!board2[i][j]) continue;
            q.push({i,j});
            board[i][j] = 0;
        }
    }

    while (!q.empty()) {
        int cr, cc;
        tie(cr, cc) = q.front(); q.pop();

        for (int i=0;i<4;i++) {
            int nr, nc;
            nr = cr + dy[i]; nc = cc + dx[i];
            if (oob(nr,nc)) continue;
            if (board2[nr][nc] == board2[cr][cc]) continue;

            if (board2[nr][nc]) {
                ans = min(ans, board[nr][nc] + board[cr][cc]);
            }
            else {
                board2[nr][nc] = board2[cr][cc];
                board[nr][nc] = board[cr][cc] + 1;
                q.push({nr,nc});
            }
        }
    }

    cout << ans;
}

void sol() {
    int n = 1;
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            if (board[i][j] && !board2[i][j]) bfs(i,j,n++);
        }
    }

    dist();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            cin >> board[i][j];
        }
    }

    sol();
}