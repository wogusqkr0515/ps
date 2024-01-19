#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> arr[1009];
int visited[1009] = {0};
int N, M;

void bfs(int num) {
    queue<int> q;
    q.push(num);
    visited[num] = 1;

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int i=0;i<arr[cur].size();i++) {
            if (visited[arr[cur][i]] == 0) {
                q.push(arr[cur][i]);
                visited[arr[cur][i]] = 1;
            }
        }
    }
}

int main() {
    int u, v;
    int cnt = 0;

    cin >> N >> M;
    for (int i=0;i<M;i++) {
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    for (int i=0;i<N;i++) {
        if (visited[i+1] == 0) {
            bfs(i+1);
            cnt++;
            // cout << cnt << " " << arr[i][j] << endl;
        }
    }
    cout << cnt << endl;
}