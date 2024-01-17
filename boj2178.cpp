#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int N, M;
vector<string> arr;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct Coordinate {
    int r, c, s;
    Coordinate(int row = 0, int col = 0, int step = 1) : r(row), c(col), s(step) {};
};

int bfs(int r, int c, vector<vector<int>> visited) {
    queue<Coordinate> q;
    char one = '1';
    q.push(Coordinate(r,c,1));
    visited[r][c] = 1;
    while (!q.empty()) {
        int curR, curC, curStep;
        curR = q.front().r; curC = q.front().c; curStep = q.front().s;
        q.pop();
        if (curR == N-1 && curC == M-1) return curStep;
        for (int i=0;i<4;i++) {
            int nextR = curR+dx[i];
            int nextC = curC+dy[i];
            if (nextR > -1 && nextR < N && nextC > -1 && nextC < M) {
                if (one == arr[nextR][nextC] && visited[nextR][nextC] == 0) {
                    visited[nextR][nextC] = 1;
                    q.push(Coordinate(nextR, nextC, curStep+1));
                }
            }
        }
    }
    return 0;
}

int main() {
    string val;
    vector<int> zeroRow;
    vector<vector<int>> visited;
    int answer;

    cin >> N >> M;
    for (int i=0;i<N;i++) {
        cin >> val;
        if (i==0) {
            for (int j=0;j<M;j++) {
                zeroRow.push_back(0);
            }
        }
        arr.push_back(val);
        visited.push_back(zeroRow);
    }
    answer = bfs(0,0,visited);
    cout << answer;
}