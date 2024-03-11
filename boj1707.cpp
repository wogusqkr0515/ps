#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int K, V, E;
int color[20001];
vector<int> graph[20001];

bool sol() {
    fill(color, color+V+1, -1);

    for (int i=1;i<=V;i++) {
        if (color[i] != -1) continue;

        queue<int> q;
        q.push(i);
        color[i] = 0;

        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for (int j=0;j<graph[cur].size();j++) {
                int nxt = graph[cur][j];
                if (color[nxt] != -1) {
                    if (color[nxt] == color[cur]) return false;
                    else continue;
                }
                color[nxt] = (color[cur] + 1) %2;
                q.push(nxt);
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K;
    for (int i=0;i<K;i++) {
        cin >> V >> E;
        for (int j=0;j<E;j++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        if (sol()) cout << "YES\n";
        else cout << "NO\n";

        for (int j=1;j<=V;j++) {
            graph[j].clear();
        }
    }
}