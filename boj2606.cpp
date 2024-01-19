#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[101];
int visited[101] = {0};

int bfs() {
    int cnt = -1;
    queue<int> q;
    q.push(1);
    visited[1] = 1;

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        cnt++;
        for (int i=0;i<graph[cur].size();i++) {
            if (visited[graph[cur][i]] == 0) {
                q.push(graph[cur][i]);
                visited[graph[cur][i]] = 1;
            }
        }
    }
    return cnt;
}

int main() {
    int computer, network, u, v, answer;

    cin >> computer >> network;

    for (int i=0;i<network;i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    answer = bfs();
    cout << answer << endl;
}