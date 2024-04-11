#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int N;

// kruskal
int unf[302];
vector<tuple<int,int,int>> edges;
// kruskal

// prim
bool chk[302];
vector<pair<int, int>> adj[302];
priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
// prim

// kruskal
int findp(int x) {
    if (unf[x] == x) return x;

    return unf[x] = findp(unf[x]);
}

bool isDiff(int a, int b) {
    a = findp(a); b = findp(b);

    if (a==b) return false;

    unf[a] = b;
    
    return true;
}

void kruskal() {
    sort(edges.begin(), edges.end());

    unf[301] = 301;
    for (int i=1;i<=N;i++) unf[i] = i;

    int ans=0, cnt=0;

    for (int i=0;i<edges.size();i++) {
        int a,b,c;
        tie(c,a,b) = edges[i];

        if (!isDiff(a,b)) continue;

        ans += c;
        cnt++;
        if (cnt == N) break;
    }

    cout << ans;
}
// kruskal

// prim
void prim() {
    fill(chk, chk+N+1, false);
    int ans=0, cnt=0;

    chk[301] = true;
    for (auto nxt : adj[301]) pq.push({nxt.X, 301, nxt.Y});

    while (!pq.empty()) {
        int a,b,c;
        tie(c,a,b) = pq.top(); pq.pop();

        if (chk[b]) continue;
        chk[b] = true;

        ans += c;
        cnt++;
        if (cnt == N) break;

        for (int i=0;i<adj[b].size();i++) {
            auto nxt = adj[b][i];
            if (chk[nxt.Y]) continue;
            pq.push({nxt.X, b, nxt.Y});
        }
    }

    cout << ans;
}
// prim

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int val ;
    cin >> N;

    for (int i=1;i<=N;i++) {
        cin >> val;
        // prim
        adj[301].push_back({val, i});
        adj[i].push_back({val, 301});
        //prim

        // kruskal
        edges.push_back({val,i, 301});
        // kruskal
    }

    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            cin >> val;
            // kruskal 알고리즘
            if (i!=j) edges.push_back({val, i, j});
            // kruskal

            // prim 알고리즘
            if (i>=j) continue;
            adj[i].push_back({val, j});
            adj[j].push_back({val, i});
            // prim
        }
    }

    kruskal();
    // prim();
}