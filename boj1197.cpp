#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int V,E;
int unf[10001];
vector<pair<int, int>> adj[10001];
tuple<int, int, int> edges[100001];

int find(int x) {
    if (unf[x] == x) return x;
    return unf[x] = find(unf[x]);
}

bool isDiff(int a, int b) {
    int v1, v2;
    v1 = find(a); v2 = find(b);

    if (v1==v2) return false;

    unf[v1] = v2;
    return true;
}

void kruskal() {
    int ans=0, cnt=0, idx=0;
    sort(edges, edges+E);

    for (int i=1;i<=V;i++) unf[i] = i;

    while (cnt<V-1) {
        int a,b,c;
        tie(c,a,b) = edges[idx++];
        if (!isDiff(a,b)) continue;

        ans += c;
        cnt++;
    }

    cout << ans;
}

void prim() {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    bool chk[10002];

    fill (chk, chk+V+1, false);

    int a,b,c, ans=0, cnt=0;
    
    chk[1] = true;
    for (auto nxt : adj[1])
        pq.push({nxt.X, 1, nxt.Y});

    while (!pq.empty()) {
        tie(c,a,b) = pq.top(); pq.pop();

        if (cnt==V-1) break;
        if (chk[b]) continue;
        chk[b] = true;

        ans += c;
        cnt++;

        for (int i=0;i<adj[b].size();i++) {
            auto nxt = adj[b][i];
            if (chk[nxt.Y]) continue;
            pq.push({nxt.X, b, nxt.Y});
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E;
    for (int i =0;i<E;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        edges[i] = {c,a,b};
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }

    // 크루스칼 알고리즘
    // kruskal();
    // 프림 알고리즘
    prim();
}