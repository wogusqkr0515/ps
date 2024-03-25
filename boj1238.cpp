#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int N, M, A;
int INF = 0x7f7f7f7f;
int answer[1001][1001];
vector<pair<int, int>> graph[1001];

void sol() {
    int ans = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

    fill(&answer[0][0], &answer[N][N], INF);

    pq.push({0, A});
    answer[A][A] = 0;

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();

        if (answer[A][cur.Y] != cur.X) continue; 
        for (auto nxt : graph[cur.Y]) {
            if (answer[A][nxt.Y] <= answer[A][cur.Y] + nxt.X) continue;
            answer[A][nxt.Y] = answer[A][cur.Y] + nxt.X;
            pq.push({answer[A][nxt.Y], nxt.Y});
        }
    }

    for (int i=1;i<=N;i++) {
        if (i==A) continue;
        while (!pq.empty()) pq.pop();

        pq.push({0, i});
        answer[i][i] = 0;

        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();

            if (answer[i][cur.Y] != cur.X) continue; 
            for (auto nxt : graph[cur.Y]) {
                if (answer[i][nxt.Y] <= answer[i][cur.Y] + nxt.X) continue;
                answer[i][nxt.Y] = answer[i][cur.Y] + nxt.X;
                pq.push({answer[i][nxt.Y], nxt.Y});
            }
        }

        ans = max(ans, answer[i][A]+answer[A][i]);
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c;
    cin >> N >> M >> A;
    for (int i=0;i<M;i++) {
        cin >> a >> b >> c;
        graph[a].push_back({c,b});
    }

    sol();
}