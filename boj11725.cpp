#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int tree[100002];
vector<int> adj[100002];

void getRoot(int node) {
    for (int i=0;i<adj[node].size();i++) {
        int nxt = adj[node][i];
        if (tree[nxt] != 0) continue;
        tree[nxt] = node;
        getRoot(nxt);
    }
}

void sol() {
    tree[1] = 1;
    for (int i=1;i<=N;i++) 
        getRoot(i);
    
    for (int i=2;i<=N;i++) cout << tree[i] << '\n';
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