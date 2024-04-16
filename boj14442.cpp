#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

struct Coord {
    int r,c,s,k;
    Coord(int row, int col, int step, int crash): r(row), c(col), s(step), k(crash) {};
};

int N, M, K;
int board[1000][1000];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool chk[11][1000][1000];

void sol() {
    bool flag = true;
    queue<Coord> q;
    q.push(Coord(0,0,1,0));
    chk[0][0][0] = true;

    while(!q.empty()) {
        Coord cur = q.front(); q.pop();

        if (cur.r == N-1 && cur.c == M-1) {
            cout << cur.s;
            flag = false;
            break;
        }

        for (int i=0;i<4;i++) {
            int nr, nc;
            nr = cur.r + dy[i]; nc = cur.c + dx[i];
            if (nr>=0 && nc>=0 && nr<N && nc<M) {
                if (!chk[cur.k][nr][nc]) {
                    // if (cur.k>0 && chk[cur.k][nr][nc]) continue;
                    if (board[nr][nc] == 0) {
                        chk[cur.k][nr][nc] = true;
                        q.push(Coord(nr, nc, cur.s+1, cur.k));
                    }
                    else if (cur.k < K && !chk[cur.k+1][nr][nc]) {
                        chk[cur.k+1][nr][nc] = true;
                        q.push(Coord(nr, nc, cur.s+1, cur.k+1));
                    }
                }
            }
        }
    }

    if (flag) cout << -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> N >> M >> K;
    for (int i=0;i<N;i++) {
        cin >> str;
        for (int j=0;j<M;j++) {
            if (str[j] == '0') board[i][j] = 0;
            else board[i][j] = 1;
        }
    }

    sol();        
}
