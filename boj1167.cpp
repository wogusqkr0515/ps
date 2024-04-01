#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// pair first, second define
#define X first
#define Y second

int V, maxNode = 0, ans = -1;
vector<pair<int, int>> adj[100001];
bool isvisit[100001];

// 트리 탐색
void dfs(int ver, int dist) {
    // maxNode, maxDistance 값 갱신
    if (dist > ans) {
        ans = dist;
        maxNode = ver;
    }

    // adj 트리 탐색
    for (int i=0;i<adj[ver].size();i++) {
        auto nxt = adj[ver][i];
        if (isvisit[nxt.X]) continue;
        isvisit[nxt.X] = true;
        dfs(nxt.X, dist + nxt.Y);
    }
}

void sol() {
    // isvisit 초기화
    fill(isvisit+1, isvisit + V+1, false);
    // 임의의 정점으로부터 가장 먼 vertex 찾기
    isvisit[1] = true;
    dfs(1,0);

    // isvisit 초기화
    fill(isvisit+1, isvisit + V+1, false);
    isvisit[maxNode] = true;
    // maxNode로부터 트리의 지름 찾기
    dfs(maxNode, 0);

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c;
    cin >> V;
    for (int i=0;i<V;i++) {
        cin >> a;
        while (true) {
            cin >> b;
            if (b==-1) break;
            cin >> c;
            adj[a].push_back({b,c});
        }
    }

    sol();
}
