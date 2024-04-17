#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Coord {
    int r,c,s,k;
    Coord(int row, int col, int step, int horsecnt): r(row), c(col), s(step), k(horsecnt) {};
};

int K,W,H;
int board[200][200];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int hdx[8] = {2, 2, 1, -1, -2, -2, -1, 1};
int hdy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
bool chk[31][200][200];

bool oob(int r, int c) {
    if (r>=0 && c>=0 && r<H && c<W) return false;
    return true;
}

void sol() {
    int nr, nc;
    bool flag = true;
    queue<Coord> q;
    q.push(Coord(0,0,0,0));
    chk[0][0][0] = true;

    while (!q.empty()) {
        Coord cur = q.front(); q.pop();

        if (cur.r == H-1 && cur.c == W-1) {
            cout << cur.s;
            flag = false;
            break;
        }
        
        if (cur.k < K) {
            for (int i=0;i<8;i++) {
                nr = cur.r + hdy[i]; nc = cur.c + hdx[i];
                if (oob(nr,nc)) continue;
                if (!chk[cur.k][nr][nc] && !chk[cur.k+1][nr][nc]) {  
                    if (board[nr][nc] == 0) {
                        chk[cur.k+1][nr][nc] = true;
                        q.push(Coord(nr, nc, cur.s+1, cur.k+1));
                    }
                }
            }
        }

        for (int i=0;i<4;i++) {
            nr = cur.r + dy[i]; nc = cur.c + dx[i];
            if (oob(nr,nc)) continue;
            if (!chk[cur.k][nr][nc]) {
                if (board[nr][nc] == 0) {
                    chk[cur.k][nr][nc] = true;
                    q.push(Coord(nr,nc,cur.s+1,cur.k));
                }
            }
        }
    }

    if (flag) cout << -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K;
    cin >> W >> H;
    for (int i=0;i<H;i++) {
        for (int j=0;j<W;j++) {
            cin >> board[i][j];
        }
    }

    sol();
}