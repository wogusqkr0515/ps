#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int N, state[1'000'001][2];
vector<int> adj[1'000'001], tree[1'000'001];

int dp(int node, bool isEarly) {
    if (state[node][isEarly] != -1)
        return state[node][isEarly];
    
    int ret = 0;
    for (int nxt : tree[node]) {
        if (isEarly) ret += min(dp(nxt, false), dp(nxt, true));
        else ret += dp(nxt, true);
    }

    return state[node][isEarly] = ret + isEarly;
}

void mktree(int cur, int pre) {
    for (int nxt : adj[cur]) {
        if (nxt == pre) continue;
        tree[cur].push_back(nxt);
        mktree(nxt, cur);
    }
}

void sol() {  
    for (int i=1;i<=N;i++) {
        state[i][0] = -1;
        state[i][1] = -1;
    }
    
    mktree(1,-1);
    cout << min(dp(1, false), dp(1, true));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b;
    cin >> N;
    for (int i=1;i<N;i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    sol();
}
