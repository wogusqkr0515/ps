#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;

int K, V, E;
string ans;
vector<int> graph[20001];
int visited[20001];

struct Pair {
    int n, s;
    Pair(int num, int step): n(num), s(step) {};
};

void dfs(int num, int step) {
    if (ans == "NO") return;
    visited[num] = step+1;
    for (int i=0;i<graph[num].size();i++) {
        // cout << "idjust num " << graph[num][i] << endl;
        if (visited[graph[num][i]] == -1) {
            dfs(graph[num][i], step+1);
        }
        else if (abs(visited[graph[num][i]] - visited[num]) > 1) {
            // cout << "Check" << endl; 
            ans = "NO";
            return; 
        }
    }
    return;
}

string bfs() {
    queue<int> q;
    q.push(1);
    visited[1] = 0;

    while(!q.empty()) {
        int curN = q.front(); q.pop();
        cout << "cur num " << curN << endl;
        for (int i=0;i<graph[curN].size();i++) {
            cout << "idjust num " << graph[curN][i] << endl;
            if (visited[graph[curN][i]] == -1) {
                q.push(graph[curN][i]);
                visited[graph[curN][i]] = visited[curN] + 1;
            }
            else if (abs(visited[graph[curN][i]] - visited[curN]) > 1) {
                cout << "Check" << endl; 
                return "NO"; 
            }
        }
    }
    return "YES";
}

int main() {
    int u,v;
    vector<string> answer;

    cin >> K;
    for (int i=0;i<K;i++) {
        cin >> V >> E;
        for (int j=0;j<E;j++) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        memset(visited, -1, sizeof(visited));
        ans = "YES";
        for (int j=1;j<=V;j++) {
            if (visited[j] == -1) dfs(j, -1);
        }
        answer.push_back(ans);

        for (int j=0;j<V;j++) {
            graph[j].clear();
        }
    }

    for (int i=0;i<K;i++) {
        cout << answer[i] << endl;
    }
}