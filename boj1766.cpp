#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int indegree[32001];
vector<int> adj[32001];

void sol() {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i=1;i<=N;i++) 
        if (indegree[i]==0) pq.push(i);

    while (!pq.empty()) {
        int cur = pq.top(); pq.pop();
        cout << cur << ' ';

        for (int i=0;i<adj[cur].size();i++) {
            int nxt = adj[cur][i];
            indegree[nxt]--;
            if (indegree[nxt] == 0) {
                pq.push(nxt);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b;
    cin >> N >> M;

    for (int i=0;i<M;i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }

    sol();
}