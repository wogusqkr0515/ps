#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

struct Pair {
    int r, c;
    Pair(int row, int col): r(row), c(col) {};
};

int N;
string graph[100];
bool visited[100][100];
bool colorVisit[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int row, int col, bool isColorBlind) {
    char color = graph[row][col];
    bool flag = false;
    if (isColorBlind && (color == 'R' || color == 'G')) flag = true;
    queue<Pair> q;
    q.push(Pair(row, col));
    if (isColorBlind) colorVisit[row][col] = true;
    else visited[row][col] = true;

    while (!q.empty()) {
        int cr, cc;
        cr = q.front().r; cc = q.front().c; q.pop();
        for (int i=0;i<4;i++) {
            int nr, nc;
            nr = cr + dy[i]; nc = cc + dx[i];
            if (nr>=0 && nc>=0 && nr<N && nc<N) {
                if (isColorBlind) {
                    if (!colorVisit[nr][nc]) {
                        if (flag) {
                            if (graph[nr][nc] == 'R' || graph[nr][nc] == 'G') {
                                colorVisit[nr][nc] = true;
                                q.push(Pair(nr, nc));
                            }
                        }
                        else {
                            if (graph[nr][nc] == color) {
                                colorVisit[nr][nc] = true;
                                q.push(Pair(nr, nc));
                            }
                        }
                    }
                } else {
                    if (!visited[nr][nc] && graph[nr][nc] == color) {
                        visited[nr][nc] = true;
                        q.push(Pair(nr, nc));
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(visited, false, sizeof(visited));
    memset(colorVisit, false, sizeof(colorVisit));
    int ans1, ans2;
    ans1 = 0; ans2 = 0;
    string str;
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> graph[i];
    }

    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            if (!visited[i][j]) {
                bfs(i, j, false);
                ans1++;
            }
            if (!colorVisit[i][j]) {
                bfs(i, j, true);
                ans2++;
            }
        }
    }
    cout << ans1 << " " << ans2;
}