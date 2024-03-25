#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second
typedef long long ll;

int N, M, A, B;
int INF = 0x7f7f7f7f;
int d[1002][1002];
vector<pair<int,int>> adj[1001];

void sol() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    fill (&d[0][0], &d[N+1][N+1], INF);

    pq.push({0,A});
    d[A][A] = 0;

    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();

        if (d[A][cur.Y] != cur.X) continue;

        for (auto nxt : adj[cur.Y]) {
            if (d[A][nxt.Y] <= d[A][cur.Y] + nxt.X) continue;
            d[A][nxt.Y] = d[A][cur.Y] + nxt.X;
            pq.push({d[A][nxt.Y], nxt.Y});
        }
    }

    cout << d[A][B];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c;
    cin >> N >> M;
    for (int i=0;i<M;i++) {
        cin >> a >> b >> c;
        adj[a].push_back({c,b});
    }
    cin >> A >> B;

    sol();
}