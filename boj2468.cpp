#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

struct Pair {
    int r, c;
    Pair(int row, int col): r(row), c(col) {};
};

int N, low, high, ans;
int graph[100][100];
int visited[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int height, int row, int col) {
    queue<Pair> q;
    q.push(Pair(row, col));
    visited[row][col] = 1;
    
    while(!q.empty()) {
        int cr, cc;
        cr = q.front().r; cc = q.front().c; q.pop();
        for (int i=0;i<4;i++) {
            int nr, nc;
            nr = cr + dy[i]; nc = cc + dx[i];
            if (nr>=0 && nc>=0 && nr<N && nc<N) {
                if (graph[nr][nc] > height && visited[nr][nc] == 0) {
                    visited[nr][nc] = 1;
                    q.push(Pair(nr, nc));
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    low = 101; high = 0; ans = 1;
    cin >> N;
    int cnt;
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            cin >> graph[i][j];
            if (graph[i][j] > high) high = graph[i][j];
            if (graph[i][j] < low) low = graph[i][j];
        }
    }
    for (int h=low;h<high;h++) {
        memset(visited, 0, sizeof(visited));
        cnt = 0;
        for (int i=0;i<N;i++) {
            for (int j=0;j<N;j++) {
                if (visited[i][j] == 0 && graph[i][j]>h) {
                    bfs(h, i, j);
                    cnt++;
                    if (cnt > ans) ans = cnt;
                }
            }
        }
    }
    cout << ans;
}