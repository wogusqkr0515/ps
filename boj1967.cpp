#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int N, maxNode = 0, ans = 0;
vector<pair<int, int>> adj[10001];
bool isvisit[10001];

void dfs(int node, int dist) {
    if (dist > ans) {
        ans = dist;
        maxNode = node;
    }
    for (int i=0;i<adj[node].size();i++) {
        auto nxt = adj[node][i];

        if (!isvisit[nxt.X]) {
            isvisit[nxt.X] = true;
            dfs(nxt.X, dist+nxt.Y);
        }
    }
}

void sol() {
    fill(isvisit, isvisit + N+1, false);
    isvisit[1] = true;
    dfs(1, 0);

    fill(isvisit, isvisit + N+1, false);
    isvisit[maxNode] = true;
    dfs(maxNode, 0);
    
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c;
    cin >> N;
    for (int i=1;i<N;i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    sol();
}