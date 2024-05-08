#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll; 
#define X first
#define Y second

vector<pair<int,int>> adj[100001];
int N, M;
ll INF = 7e11;
ll dist[100001];

void sol() {
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    for (int i=1;i<=N;i++) dist[i] = INF;

    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();

        if (cur.Y == N) {
            cout << cur.X;
            break;
        }
        if (dist[cur.Y] != cur.X) continue;

        for (auto nxt : adj[cur.Y]) {
            ll nd = (nxt.X-cur.X) % M;
            if (nd<0) nd += M;
            nd += cur.X+1;
            if (nd >= dist[nxt.Y]) continue; 
            dist[nxt.Y] = nd;
            pq.push({dist[nxt.Y], nxt.Y});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i=0;i<M;i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back({i,b});
        adj[b].push_back({i,a});
    }

    sol();
}