#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Pair {
    int r, c;
    Pair(int row, int col): r(row), c(col) {};
};

int M, N, K;
int graph[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int row, int col) {
    int cnt = 0;
    queue<Pair> q;
    q.push(Pair(row, col));
    graph[row][col] = 3;

    while (!q.empty()) {
        int cR, cC;
        cR = q.front().r; cC = q.front().c; q.pop();
        cnt++;
        for (int i=0;i<4;i++) {
            int nR, nC;
            nR = cR + dy[i]; nC = cC + dx[i];
            if (nR >=0 && nC >= 0 && nR < M && nC < N) {
                if (graph[nR][nC] == 0) {
                    graph[nR][nC] = 3;
                    q.push(Pair(nR, nC));
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

    int width;
    vector<int> ans;
    cin >> M >> N >> K;
    for (int i=0;i<K;i++) {
        int ax, ay, bx, by;
        cin >> ax >> ay >> bx >> by;
        for (int y=ay;y<by;y++) {
            for (int x=ax;x<bx;x++) {
                graph[y][x] = 1;
            }
        }
        
    }
    // cout << "chk" << endl;
    for (int i=0;i<M;i++) {
        for (int j=0;j<N;j++) {
            if (graph[i][j] == 0) {
                width = bfs(i, j);
                ans.push_back(width);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int i=0;i<ans.size();i++)
        cout << ans[i] << " ";
}