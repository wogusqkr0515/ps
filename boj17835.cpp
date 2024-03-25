#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second
typedef long long ll;

int N, M, K;
ll INF = 0x7f7f7f7f7f7f;
ll d[100002];
vector<pair<ll, int>> adj[100002];
priority_queue<pair<ll, int>, 
                vector<pair<ll, int>>, 
                greater<pair<ll, int>>> pq;

void sol() {
    ll ans = 0;
    int city = 0;
    
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (d[cur.Y] != cur.X) continue;

        for (auto nxt : adj[cur.Y]) {
            if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }

    for (int j=1;j<=N;j++) {
        if (ans < d[j]) { ans = d[j]; city = j; }
    }

    cout << city << '\n' << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b;
    ll c;
    cin >> N >> M >> K;
    for (int i=0;i<M;i++) {
        cin >> a >> b >> c;
        adj[b].push_back({c,a});
    }
    fill(d, d+ N+1, INF);
    for (int i=0;i<K;i++) {
        cin >> a;
        d[a] = 0;
        pq.push({0, a});
    }
    
    sol();
}