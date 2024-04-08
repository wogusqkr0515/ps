#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<int> adj[1001];
int indeg[1001];

void sol() {
    queue<int> q;
    vector<int> result;
    for (int i=1;i<=N;i++) {
        if (indeg[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        result.push_back(cur);
        for (int i=0;i<adj[cur].size();i++) {
            indeg[adj[cur][i]]--;
            if (indeg[adj[cur][i]] == 0) q.push(adj[cur][i]);
        }
    }

    if (result.size() != N) cout << 0;
    else for (int iter : result) cout << iter << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, val;
    int mval[1000];
    cin >> N >> M;
    for (int i=0;i<M;i++) {
        cin >> n;
        for (int j=0;j<n;j++) 
            cin >> mval[j];
        
        for (int j=0;j<n-1;j++) {
            for (int k=j+1;k<n;k++) {
                adj[mval[j]].push_back(mval[k]);
                indeg[mval[k]]++;
            }
        }
    }

    sol();
}