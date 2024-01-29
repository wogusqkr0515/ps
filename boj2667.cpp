#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

vector<string> graph;
int visited[25][25];
int N;
char one = '1';
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

struct Pair {
    int r, c;
    Pair(int row, int col): r(row), c(col) {};
};

int bfs(int r, int c) {
    int cnt = 0;
    queue<Pair> q;
    q.push(Pair(r,c));
    visited[r][c] = 1;

    while (!q.empty()) {
        int curR, curC;
        curR = q.front().r; curC = q.front().c; q.pop();
        cnt++;
        for (int i=0;i<4;i++) {
            int nextR, nextC;
            nextR = curR + dy[i]; nextC = curC + dx[i];
            if (nextR >=0 && nextR <N && nextC >=0 && nextC < N) {
                if (graph[nextR][nextC] == one && visited[nextR][nextC] == 0) {
                    q.push(Pair(nextR, nextC));
                    visited[nextR][nextC] = 1;
                }
            }
        }
    }
    return cnt;
}

int main() {
    vector<int> answer;
    int cnt, width;
    string val;
    cnt = 0;


    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> val;
        graph.push_back(val);
    }
    
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            if (graph[i][j] == one && visited[i][j] == 0) {
                width = bfs(i, j);
                cnt++;
                answer.push_back(width);
            }
        }   
    }
    sort(answer.begin(), answer.end());
    cout << cnt << endl;
    for (int i=0;i<answer.size();i++) 
        cout << answer[i] << endl;

}