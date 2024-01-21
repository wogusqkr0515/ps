#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<int> graph[10001];
int visited[10001];

int bfs(int num) {
    int cnt = 0;
    queue<int> q;
    q.push(num);
    visited[num] = 1;

    while (!q.empty()) {
        int curN = q.front(); q.pop();
        cnt++;
        for (int i=0;i<graph[curN].size();i++) {
            if (visited[graph[curN][i]] == 0) {
                visited[graph[curN][i]] = 1;
                q.push(graph[curN][i]);
            }
        }
    }
    return cnt;
}

int main() {
    int N, M, u, v, cnt, answerCnt = 0;
    vector<int> answer;

    cin >> N >> M;
    for (int i=0;i<M;i++) {
        cin >> u >> v;
        graph[v].push_back(u);
    }

    for (int i=1;i<=N;i++) {
        memset(visited, 0, sizeof(visited));
        cnt = bfs(i);
        if (cnt > answerCnt) { answer.clear(); answer.push_back(i); answerCnt = cnt; }
        else if (cnt == answerCnt) answer.push_back(i);
    }
    for (int i=0;i<answer.size();i++) cout << answer[i] << " ";
}