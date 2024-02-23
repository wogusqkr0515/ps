#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int graph[50][50];
int N, M, d;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

struct Pair {
    int r, c;
    Pair(int row, int col): r(row), c(col) {};
};

int bfs(int row, int col) {
    int cnt = 0;
    queue<Pair> q;
    q.push(Pair(row, col));
    graph[row][col] = 2;

    while (!q.empty()) {
        row = q.front().r; col= q.front().c; q.pop();
        cnt++;
        for (int i=0;i<4;i++) {
            int nextR, nextC;
            d = (d+3)%4;
            nextR = row + dy[d]; nextC = col + dx[d];
            if (graph[nextR][nextC] == 0) {
                q.push(Pair(nextR, nextC));
                graph[nextR][nextC] = 2;
                break;
            } else if (i == 3) {
                int nextD = (d+2)%4;
                nextR = row + dy[nextD]; nextC = col + dx[nextD];
                if (graph[nextR][nextC] != 1) {
                    q.push(Pair(nextR, nextC));
                    cnt--;
                    break;
                }
                return cnt;
            }
        }
    }
    return cnt;
}

int main() {
    int r, c, val, answer;

    cin >> N >> M;
    cin >> r >> c >> d;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            cin >> val;
            graph[i][j] = val;
        }
    }
    answer = bfs(r, c);
    cout << answer << endl;
}