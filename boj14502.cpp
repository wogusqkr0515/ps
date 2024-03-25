#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Coord {
    int r, c;
    Coord(int row, int col): r(row), c(col) {};
};

int N,M, ans;
int board[10][10], board2[10][10];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<Coord> virus, zero;

void bfs() {
    queue<Coord> q;
    for (int i=0;i<virus.size();i++) 
        q.push(virus[i]);

    while (!q.empty()) {
        int cr, cc, cs;
        cr = q.front().r; cc = q.front().c; q.pop();

        for (int i=0;i<4;i++) {
            int nr, nc;
            nr = cr + dy[i]; nc = cc + dx[i];
            if (nr>=0 && nc>=0 && nr<N && nc<M) {
                if (board2[nr][nc] == 0) {
                    board2[nr][nc] = 2;
                    q.push(Coord(nr, nc));
                }
            }
        }
    }
    int cnt = 0;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            if (board2[i][j] == 0) cnt++;
        }
    }
    ans = max(ans, cnt);
}

void copy() {
    for (int i=0;i<N;i++)
        for (int j=0;j<M;j++)
            board2[i][j] = board[i][j];
}

void sol() {
    // cout << endl;
    int r, c, idx, cnt;
    ans = 0;
    
    for (int i=0;i<zero.size()-2;i++) {
        board[zero[i].r][zero[i].c] = 1;
        for (int j=i+1;j<zero.size()-1;j++) {
            board[zero[j].r][zero[j].c] = 1;
            for (int k=j+1;k<zero.size();k++) {
                board[zero[k].r][zero[k].c] = 1;
                copy();
                bfs();
                board[zero[k].r][zero[k].c] = 0;
            }
            board[zero[j].r][zero[j].c] = 0;
        }
        board[zero[i].r][zero[i].c] = 0;
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt = 0;
    cin >> N >> M;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) zero.push_back(Coord(i, j));
            if (board[i][j] == 2) virus.push_back(Coord(i,j));
        }
    }

    sol();
}