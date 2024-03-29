#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Pair {
    int c, s;
    Pair(int coord, int step): c(coord), s(step) {};
};

int N, K;
bool isvisit[100001];

void sol() {
    fill(isvisit, isvisit + 100000, false);

    queue<Pair> q;
    q.push(Pair(N,0));
    isvisit[N] = true;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        if (cur.c == K) {
            cout << cur.s;
            break;
        }
        if (cur.c*2 <= 100000) {
            if (!isvisit[cur.c*2]) {
                isvisit[cur.c*2] = true;
                q.push(Pair(cur.c*2, cur.s));
            }
        }

        if (cur.c-1>=0) {
            if (!isvisit[cur.c-1]) {
                isvisit[cur.c-1] = true;
                q.push(Pair(cur.c-1, cur.s+1));
            }
        }

        if (cur.c+1<=K) {
            if (!isvisit[cur.c+1]) {
                isvisit[cur.c+1] = true;
                q.push(Pair(cur.c+1, cur.s+1));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    sol();
}