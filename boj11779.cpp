#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int N, M, st, ed;
int INF = 2e9;
int d[1005], pre[1005];
vector<pair<int, int>> graph[1005];
priority_queue< pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

void sol() {
    int cnt = 1, idx = ed;
    vector<int> result;
    d[st] = 0;
    // pre[st] = st;
    pq.push(make_pair(0, st));

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (d[cur.Y] != cur.X) continue;

        for (auto nxt : graph[cur.Y]) {
            if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pre[nxt.Y] = cur.Y;
            pq.push(make_pair(d[nxt.Y], nxt.Y));
        }
    }
    cout << d[ed] << '\n';
    
    while (true) {
        if (idx == st) break;
        
        result.push_back(idx);
        idx = pre[idx];
    }
    result.push_back(idx);
    reverse(result.begin(), result.end());
    cout << result.size() << '\n';
    for (auto iter : result)
        cout << iter << " ";
    // for (int i=1;i<=N;i++) cout << pre[i] << " ";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c;
    cin >> N;
    cin >> M;
    for (int i=0;i<M;i++) {
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(c, b));
    }
    cin >> st >> ed;
    fill(d, d+N +1, INF);
    fill(pre, pre+N+1, 0);

    sol();
}