#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

struct Pair {
    int r, c, d;
    Pair(int row, int col, int depth=0): r(row), c(col), d(depth) {};
};

vector<int> chess;
vector<Pair> cur, tar;
int visited[300][300];
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int bfs(int idx) {
    int cnt = 0;
    int N, row, col;
    N = chess[idx]; row = cur[idx].r; col = cur[idx].c;
    queue<Pair> q;
    q.push(Pair(row, col, 0));
    visited[row][col] = 1;

    while(!q.empty()) {
        int cr, cc;
        cr = q.front().r; cc = q.front().c; cnt = q.front().d; q.pop();
        if (cr == tar[idx].r && cc == tar[idx].c) return cnt;
        for (int i=0;i<8;i++) {
            int nr, nc;
            nr = cr + dy[i]; nc = cc + dx[i];
            if (nr>=0 && nc>=0 && nr<N && nc<N) {
                if (visited[nr][nc] == 0) {
                    visited[nr][nc] = 1;
                    q.push(Pair(nr, nc, cnt+1));
                }
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, a, b, c;
    cin >> T;
    for (int i=0;i<T;i++) {
        cin >> a;
        chess.push_back(a);
        cin >> b >> c;
        cur.push_back(Pair(b, c));
        cin >> b >> c;
        tar.push_back(Pair(b, c));
    }
    for (int i=0;i<T;i++) {
        cout << bfs(i) << '\n';
        memset(visited, 0, sizeof(visited));
    }

}