#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, H;
vector<vector<vector<int>>> graph;
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

struct Coord {
    int f, r, c, d;
    Coord(int floor, int row, int col, int day): f(floor), r(row), c(col), d(day) {};
};

int bfs() {
    int cnt = 0;
    queue<Coord> q;
    for (int i=0;i<H;i++) {
        for (int j=0;j<N;j++) {
            for (int z=0;z<M;z++) {
                if (graph[i][j][z] == 1) {
                    q.push(Coord(i,j,z, 0));
                }
            }
        }
    }
    
    while(!q.empty()) {
        int curF, curR, curC;
        curF = q.front().f; curR = q.front().r; curC = q.front().c; cnt = q.front().d; q.pop();
        for (int i=0;i<6;i++) {
            int nF, nR, nC;
            nF = curF + dz[i]; nR = curR + dy[i]; nC = curC + dx[i];
            if (nF>=0 && nR>=0 && nC>=0 && nF<H && nR < N && nC<M) {
                if (graph[nF][nR][nC] == 0) {
                    graph[nF][nR][nC] = 1;
                    q.push(Coord(nF, nR, nC, cnt+1));
                }
            }
        }
    }
    return cnt;
}

int main() {
    int val, answer;
    vector<int> v;
    vector<vector<int>> vv;

    cin >> M >> N >> H;
    for (int i=0;i<H;i++) {
        for (int j=0;j<N;j++) {
            for (int z=0;z<M;z++) {
                cin >> val;
                v.push_back(val);
            }
            vv.push_back(v);
            v.clear();
        }
        graph.push_back(vv);
        vv.clear();
    }

    answer = bfs();
    bool flag = false;
    for (int i=0;i<H;i++) {
        if (flag) break;
        for (int j=0;j<N;j++) {
            if (flag) break;
            for (int z=0;z<M;z++) {
                if (flag) break;
                if (graph[i][j][z] == 0) flag = true;
            }
        }
    }
    if (flag) cout << -1;
    else cout << answer;
}