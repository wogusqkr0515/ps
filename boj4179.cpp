#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

struct Pair {
    int r,c, d;
    Pair(int row, int col, int depth): r(row), c(col), d(depth) {};
};

int R, C;
vector<string> graph;
bool visited[1000][1000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char W, S, J, F;

void bfs() {
    int js, fs;
    queue<Pair> jq, fq;
    for (int i=0;i<R;i++) {
        for (int j=0;j<C;j++) {
            if (graph[i][j] == J) {
                visited[i][j] = true;
                graph[i][j] = S;
                jq.push(Pair(i,j,0));
            }
            if (graph[i][j] == F) {
                fq.push(Pair(i,j,0));
            }
        }
    }

    js = 0; fs = 0;
    while (!jq.empty()) {
        while (!fq.empty()) {
            int fr, fc;
            fr = fq.front().r; fc = fq.front().c; fs = fq.front().d; 
            if (fs>js) break;
            fq.pop();
            for (int i=0;i<4;i++) {
                int fnr, fnc;
                fnr = fr + dy[i]; fnc = fc + dx[i];
                if (fnr>=0 && fnc>=0 && fnr<R && fnc<C) {
                    if (graph[fnr][fnc] == S) {
                        graph[fnr][fnc] = F;
                        fq.push(Pair(fnr, fnc, fs+1));
                    }
                }
            }
        }

        while (true) {
            if (jq.empty()) break;
            if (!fq.empty() && fs<=js) break;
            int jr, jc;
            jr= jq.front().r; jc = jq.front().c; js = jq.front().d; jq.pop();

            if (jr==0 || jc==0 || jr==R-1 || jc==C-1) {
                cout << js+1 << '\n';
                return;
            }

            for (int i=0;i<4;i++) {
                int jnr, jnc;
                jnr = jr + dy[i]; jnc = jc + dx[i];
                if (jnr>=0 && jnc>=0 && jnr<R && jnc<C) {
                    if (!visited[jnr][jnc] && graph[jnr][jnc] == S) {
                        visited[jnr][jnc] = true;
                        jq.push(Pair(jnr, jnc, js+1));
                    }
                }
            }
        }
    }

    cout << "IMPOSSIBLE";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string inp;
    W = '#'; S = '.';
    J = 'J'; F = 'F';
    cin >> R >> C;
    for (int i=0;i<R;i++) {
        cin >> inp;
        graph.push_back(inp);
    }

    memset(visited, false, sizeof(visited));
    bfs();
}
