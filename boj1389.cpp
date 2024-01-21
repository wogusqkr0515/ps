#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<int> graph[101];
int visited[101];
int N;

struct Pair {
    int n, d;
    Pair(int num, int depth): n(num), d(depth) {};
};

int bfs(int num) {
    int sum = 0;
    queue<Pair> q;
    q.push(Pair(num, 0));
    visited[num] = 1;

    while(!q.empty()) {
        int curN, curD;
        curN = q.front().n; curD = q.front().d; q.pop();
        sum += curD;
        for (int i=0;i<graph[curN].size();i++) {
            if (visited[graph[curN][i]] == 0) {
                visited[graph[curN][i]] = 1;
                q.push(Pair(graph[curN][i], curD+1));
            }
        }
    }

    return sum;
}

int main() {
    int M, u, v, cnt, answer, answerCnt = 100000;

    cin >> N >> M;
    for (int i=0;i<M;i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i=1;i<=N;i++) {
        memset(visited, 0, sizeof(visited));
        cnt = bfs(i);
        if (answerCnt > cnt) { answerCnt = cnt; answer = i; }
    }
    cout << answer << endl;
}