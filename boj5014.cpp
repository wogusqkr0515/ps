#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

struct Pair {
    int f, d;
    Pair(int floor, int depth): f(floor), d(depth) {};
};

int F, S, G, U, D;

int bfs() {
    int dep;
    map<int, int> m;
    queue<Pair> q;
    q.push(Pair(S, 0));
    m[S] = 1;

    while (!q.empty()) {
        int cf, cd;
        cf = q.front().f; dep = q.front().d; q.pop();
        if (cf == G) return dep;
        for (int i=0;i<2;i++) {
            int nf;
            if (i%2==0) nf = cf + U;
            else nf = cf - D;
            if (nf>=1 && nf<=F) {
                if (m[nf] == 0) {
                    m[nf] = 1;
                    q.push(Pair(nf, dep+1));
                }
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ans;
    cin >> F >> S >> G >> U >> D;
    ans = bfs();
    if (ans == -1) cout << "use the stairs";
    else cout << ans;
}