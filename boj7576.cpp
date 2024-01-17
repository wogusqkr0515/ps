#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Coordinate {
    int r,c,d;
    Coordinate(int row, int col, int days): r(row), c(col), d(days) {};
};

int M,N;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<vector<int>> arr;
queue<Coordinate> q;

int bfs() {
    int days = 0;
    while (!q.empty()) {
        int curR, curC;
        curR = q.front().r; curC = q.front().c; days = q.front().d;
        q.pop();
        for (int i=0;i<4;i++) {
            int nextR = curR + dx[i];
            int nextC = curC + dy[i];
            if (nextR >= 0 && nextC >= 0 && nextR < N && nextC < M) {
                if (arr[nextR][nextC] == 0) {
                    arr[nextR][nextC] = 1;
                    q.push(Coordinate(nextR, nextC, days+1));
                }
            }
        }
    }
    return days;
}

int main() {
    int val, answer;
    vector<int> iter;

    cin >> M >> N;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            cin >> val;
            iter.push_back(val);
        }
        arr.push_back(iter);
        iter.clear();
    }
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            if (arr[i][j] == 1) q.push(Coordinate(i,j,0));
        }
    }
    answer = bfs();
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            if (arr[i][j] == 0) { answer = -1; break; }
        }
    }
    cout << answer << endl;
}