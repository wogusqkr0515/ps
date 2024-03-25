#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second
typedef long long ll;

int V,E, A, B;
int INF = 0x7f7f7f7f;
int answer[805];
vector<pair<int, int>> graph[805];

ll sol(int st, int ed) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    fill(answer, answer+V+1, INF);

    pq.push({0,st});
    answer[st] = 0;

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();

        if (cur.Y == ed) return answer[ed];
        if (answer[cur.Y] != cur.X) continue;

        for (auto nxt : graph[cur.Y]) {
            if (answer[nxt.Y] <= answer[cur.Y] + nxt.X) continue;
            answer[nxt.Y] = answer[cur.Y] + nxt.X;
            pq.push({answer[nxt.Y], nxt.Y});
        }
    }

    return answer[ed];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c;
    cin >> V >> E;
    for (int i=0;i<E;i++) {
        cin >> a >> b >> c;
        graph[a].push_back({c,b});
        graph[b].push_back({c,a});
    }
    cin >> A >> B;
    
    ll ans1 = sol(1,A) + sol(A,B) + sol(B, V);
    ll ans2 = sol(1,B) + sol(B,A) + sol(A, V);
    ll ans = min(ans1, ans2);

    if (ans>=INF) cout << -1;
    else cout << ans;
}