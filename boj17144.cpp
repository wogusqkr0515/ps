#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Coord {
    int r, c, v;
    Coord(int row, int col, int val): r(row), c(col), v(val) {};
};

int R,C,T, answer = 0;
int air[2];
int board[50][50];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<Coord> q;

bool oob(int row, int col) {
    return (row>=0 && col>=0 && row<R && col<C);
}

void clean(bool flag) {
    int r, c, nr, nc, dir = 3;

    r = air[0]-1; c = 0;
    while (!(r==air[0] && c == 1)) {
        nr = r + dy[dir]; nc = c + dx[dir];
        if (!oob(nr, nc) || nr==air[1]) {
            dir = (dir+1) % 4;
            nr = r + dy[dir]; nc = c + dx[dir];
        }
        board[r][c] = board[nr][nc];
        r = nr; c = nc;
    }
    board[air[0]][1] = 0;

    r = air[1]+1; c = 0; dir = 1;
    while (!(r==air[1] && c == 1)) {
        nr = r + dy[dir]; nc = c + dx[dir];
        if (!oob(nr, nc) || nr==air[0]) {
            if (dir == 0) dir = 3;
            else dir--;
            nr = r + dy[dir]; nc = c + dx[dir];
        }
        board[r][c] = board[nr][nc];
        r = nr; c = nc;
    }
    board[air[1]][1] = 0;

    int ans = 0;
    for (int i=0;i<R;i++) {
        for (int j=0;j<C;j++) {
            if (board[i][j] > 0) q.push(Coord(i, j, board[i][j]));
            if (flag && board[i][j] > 0) ans += board[i][j];
        }
    }
    answer = ans;
}

void bfs() {
    while (!q.empty()) {
        int r, c, val;
        r = q.front().r; c = q.front().c; 
        val = q.front().v; q.pop();
        for (int i=0;i<4;i++) {
            int nr, nc;
            nr = r + dy[i]; nc = c + dx[i];
            if (oob(nr, nc)) {
                if (board[nr][nc] != -1) {
                    board[r][c] -= val/5;
                    board[nr][nc] += val/5;
                }
            }
        }
    }
}

void sol() {
    for (int i=0;i<T;i++) {
        bfs();
        clean(i==T-1);
    }

    cout << answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    bool flag = true;
    cin >> R >> C >> T;
    for (int i=0;i<R;i++) {
        for (int j=0;j<C;j++) {
            cin >> board[i][j];
            if (board[i][j] > 0) q.push(Coord(i,j,board[i][j]));
            if (board[i][j] == -1) {
                if (flag) air[0] = i;
                else air[1] = i; 
                flag = false;
            }
        }
    }

    sol();
}