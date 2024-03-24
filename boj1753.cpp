#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second

struct cmp {
    bool operator()(const pair<int, int> a, const pair<int, int> b) const {
        return a.X > b.X; 
    }
};

const int INF = 2e9;
int V,E, start;
int dist[20005];
// 거리 정점
vector<pair<int, int>> graph[20005];
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

void sol() {
    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int curv, curd;
        curv = pq.top().Y; curd = pq.top().X; pq.pop();
        if (dist[curv] != curd) continue;
        for (int i=0;i<graph[curv].size();i++) {
            int nextv, nextd;
            nextv = graph[curv][i].Y; nextd = graph[curv][i].X;
            if (dist[nextv] <= dist[curv] + nextd) continue;
            dist[nextv] = dist[curv]+nextd;
            pq.push(make_pair(dist[curv] + nextd, nextv));
        }
    }
    for (int i=1;i<=V;i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b, d;
    cin >> V >> E;
    cin >> start;
    for (int i=0;i<E;i++) {
        cin >> a >> b >> d;
        graph[a].push_back(make_pair(d,b));
    }
    fill(dist, dist + V + 1, INF);
    
    sol();
}