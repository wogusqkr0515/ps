#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;
#define X first
#define Y second

int N, M, A, B, ans = 2e9;
vector<pair<int,int>> adj[100001];
ll C, lo, hi, INF = 9e17;
ll dist[100002];

bool chk(int x) {
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    fill(dist, dist+N+1, INF);
    dist[A] = 0;
    pq.push({0,A});

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();

        if (dist[cur.Y] != cur.X) continue;

        for (auto nxt : adj[cur.Y]) {
            if (nxt.X > x) continue;
            if (dist[nxt.Y] <= dist[cur.Y] + nxt.X) continue;

            dist[nxt.Y] = dist[cur.Y] + nxt.X;
            pq.push({dist[nxt.Y], nxt.Y});            
        }
    }

    if (dist[B] > C) return false;
    return true;
}

void sol() {
    while (lo+1<hi) {
        ll mid = (lo+hi) /2;
        if (chk(mid)) hi = mid;
        else lo = mid;
    }

    if (chk(hi)) cout << hi;
    else cout << -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c, tmp;
    cin >> N >> M >> A >> B >> C;
    while (M--) {
        cin >> a >> b >> c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
        tmp = max(tmp, c);
    }

    lo = 0; hi = tmp+1;
    sol();
}