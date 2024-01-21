#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
vector<int> graph[100];
int visited[100];

void dfs(int start, int num) {
    for (int i=0;i<graph[num].size();i++) {
        if (visited[graph[num][i]] == 0) {
            visited[graph[num][i]] = 1;
            dfs(start, graph[num][i]);
        }
    }
}

int main() {
    int val;

    cin >> N;
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            cin >> val;
            if (val == 1) graph[i].push_back(j);
        }
    }
    for (int i=0;i<N;i++) {
        memset(visited, 0, sizeof(visited));
        dfs(i, i);
        for (int j=0;j<N;j++) cout << visited[j] << " ";
        cout << endl;
    }
}