#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> graph[51];
int visited[51];

struct Pair {
    int n, d;
    Pair(int num, int depth): n(num), d(depth) {};
};

int bfs(int num) {
    int depth = 0;
    queue<Pair> q;
    q.push(Pair(num, 0));
    visited[num] = 1;

    while (!q.empty()) {
        int curN = q.front().n; depth = q.front().d; q.pop();
        for (int i=0;i<graph[curN].size();i++) {
            if (visited[graph[curN][i]] == 0) {
                visited[graph[curN][i]] = 1;
                q.push(Pair(graph[curN][i], depth+1));
            }
        }
    }
    return depth;
}

int main() {
    int N, u, v, cnt, answerCnt = 1000;
    vector<int> answer;

    cin >> N;
    while (true) {
        cin >> u >> v;
        if (u == -1 && v == -1) break;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i=1;i<=N;i++) {
        memset(visited, 0, sizeof(visited));
        cnt = bfs(i);
        if (cnt < answerCnt) { answer.clear(); answer.push_back(i); answerCnt = cnt; }
        else if (cnt == answerCnt) answer.push_back(i);
    }
    sort(answer.begin(), answer.end());
    cout << answerCnt << " " << answer.size() << endl;
    for (int i=0;i<answer.size();i++) cout << answer[i] << " ";
}