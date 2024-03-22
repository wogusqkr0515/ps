#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int indegrees[32005];
vector<int> v[32005];

void sol() {
    queue<int> q;
    vector<int> result;
    for (int i =1;i<=N;i++) {
        if (indegrees[i]==0) q.push(i);
    }

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        result.push_back(cur);
        // cout << cur << endl;
        for (int i=0;i<v[cur].size();i++) {
            indegrees[v[cur][i]]--;
            if (indegrees[v[cur][i]] == 0) q.push(v[cur][i]);
        }
    }

    for (auto iter : result) cout << iter << " ";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> N >> M;
    for (int i=0;i<M;i++) {
        cin >> a >> b;
        v[a].push_back(b);
        indegrees[b]++;
    }

    sol();
}