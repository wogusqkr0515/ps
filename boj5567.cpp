#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[501];
int visited[501] = {0};
int N, M;

struct Pair {
    int n, d;
    Pair(int num, int depth): n(num), d(depth) {};
};

int bfs() {
    int cnt = -1;
    queue<Pair> q;
    q.push(Pair(1,0));
    visited[1] = 1;

    while (!q.empty()) {
        int curN, curD;
        curN = q.front().n; curD = q.front().d; q.pop();
        cnt++;
        // cout << curN << " " << cnt << endl;
        for (int i=0;i<graph[curN].size();i++) {
            if (visited[graph[curN][i]] == 0 && curD <2) {
                q.push(Pair(graph[curN][i], curD+1));
                visited[graph[curN][i]] = 1;
            }
        }
    }
    return cnt;
}

int main() {
    int u, v, answer;
    
    cin >> N >> M;
    for (int i=0;i<M;i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    answer = bfs();
    cout << answer << endl;
}