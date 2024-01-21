#include <iostream>
#include <vector>
#include <queue>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> graph[20001];
vector<int> answer;
int visited[20001];
int step;

struct Pair {
    int n, d;
    Pair(int num, int depth): n(num), d(depth) {};
};

int bfs() {
    int cnt = 0;
    queue<Pair> q;
    q.push(Pair(1, 0));
    visited[1] = 1;
    int curN, curD;
    curN = 1; curD = -1;

    while (!q.empty()) {
        if (curD == q.front().d) cnt++;
        else { cnt = 1; step = q.front().d; answer.clear(); }
        curN = q.front().n; curD = q.front().d; q.pop();
        answer.push_back(curN);
        for (int i=0;i<graph[curN].size();i++) {
            if (visited[graph[curN][i]] == 0) {
                visited[graph[curN][i]] = 1;
                q.push(Pair(graph[curN][i], curD+1));
            }
        }
    }

    return cnt;
}

int main() {
    int N, M, u, v, cnt;

    cin >> N >> M;
    for (int i=0;i<M;i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cnt = bfs();
    sort(answer.begin(), answer.end());
    cout << answer[0] << " " << step << " " << cnt << endl;
}