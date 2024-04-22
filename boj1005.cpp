#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int T,N,K,W;
int needs[1001], indegree[1001];
vector<int> order[1001];

void sol() {
    priority_queue< pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    int ans = 0;

    for (int i=1;i<=N;i++) {
        if (indegree[i] == 0) pq.push({needs[i],i});
    }

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (cur.Y == W) {
            cout << cur.X << '\n';
            return;
        }

        for (int i=0;i<order[cur.Y].size();i++) {
            int nxt = order[cur.Y][i];
            indegree[nxt]--;
            if (indegree[nxt] == 0) {
                pq.push({cur.X+needs[nxt], nxt});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for (int i=0;i<T;i++) {
        cin >> N >> K;
        for (int j=1;j<=N;j++) {
            cin >> needs[j];
            indegree[j] = 0;
            order[j].clear();
        }
        
        int a,b;
        for (int j=0;j<K;j++) {
            cin >> a >> b;
            order[a].push_back(b);
            indegree[b]++;
        }
        cin >> W;

        sol();
    }
}