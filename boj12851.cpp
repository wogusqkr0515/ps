#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

struct Pair {
    int n, t;
    Pair(int num, int time): n(num), t(time) {};
};

int N, K;
int isvisit[100002];
unordered_map<int, int> tmap;

void sol() {
    fill(isvisit, isvisit+100001, false);

    int cnt = 0, ft = 2e9;
    queue<Pair> q;
    q.push(Pair(N,0));
    isvisit[N] = true;

    while (!q.empty()) {
        int cn, ct;
        cn = q.front().n; ct = q.front().t; q.pop();
        
        if (cn == N && ct > 0) continue;
        if (cn==K) {
            if (ft < ct) break;
            if (ft > ct) {
                ft = ct;
            }
            cnt++;
        }
        
        if (cn*2 <= K+1 && (!isvisit[cn*2]|| tmap[cn*2] == ct+1)) {
            q.push(Pair(cn*2, ct+1));
            if (tmap[cn*2]==0) tmap[cn*2] = ct+1;
            isvisit[cn*2] = true;
        }
        if (cn+1<=K && (!isvisit[cn+1]|| tmap[cn+1] == ct+1)) {
            q.push(Pair(cn+1, ct+1));
            if (tmap[cn+1]==0) tmap[cn+1] = ct+1;
            isvisit[cn+1] = true;
        }
        if (cn-1>=0 && (!isvisit[cn-1]|| tmap[cn-1] == ct+1)) {
            q.push(Pair(cn-1, ct+1));
            if (tmap[cn-1]==0) tmap[cn-1] = ct+1;
            isvisit[cn-1] = true;
        }
        
    }
    cout << ft << '\n' << cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    sol();
}