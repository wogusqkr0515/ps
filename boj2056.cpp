#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int N;
int times[10001], indegrees[10001];
vector<int> adj[10001];

void sol() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

    for (int i=1;i<=N;i++) {
        if (!indegrees[i]) pq.push({times[i],i});
    }

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();

        for (auto nxt : adj[cur.Y]) {
            indegrees[nxt]--;
            if (!indegrees[nxt]) pq.push({cur.X + times[nxt], nxt});
        }

        if (pq.empty()) cout << cur.X;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, num;
    cin >> N;
    for (int i=1;i<=N;i++) {
        cin >> times[i];
        cin >> n;
        for (int j=0;j<n;j++) {
            cin >> num;
            adj[num].push_back(i);
            indegrees[i]++;
        }
    }

    sol();
}
