#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second

bool flag = false;
int N, P, K;
int INF = 1e9 + 100;
int dist[1002];
vector<pair<int,int>> adj[1001];

bool check(int target) {
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    fill(dist, dist+N+1, INF);

    pq.push({0,1});
    dist[1] = 0;

    while (!pq.empty()) {
        int curn, curm;
        curn = pq.top().Y; curm = pq.top().X; pq.pop();

        if (dist[curn] < curm) continue;

        for (int i=0;i<adj[curn].size();i++) {
            auto nxt = adj[curn][i];

            if (dist[nxt.Y] <= dist[curn] + (nxt.X > target)) continue;
            
            dist[nxt.Y] = dist[curn] + (nxt.X > target);
            pq.push({dist[nxt.Y], nxt.Y});
        }
    }
    if (dist[N] == INF) {
        flag = true;
        return false;
    }
    return dist[N] <= K;
}

void sol() {
    int lo, hi, mid;
    lo = -1; hi = 1000001;
    
    while (lo+1<hi) {
        mid = (lo+hi)/2;

        if (check(mid)) hi = mid;
        else lo = mid;
        if (flag) break;
    }
    if (flag) cout << -1;
    else cout << hi;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c;
    cin >> N >> P >> K;
    for (int i=0;i<P;i++) {
        cin >> a >> b >> c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }

    sol();
}