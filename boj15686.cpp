#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

struct Pair {
    int r, c;
    Pair(int row, int col): r(row), c(col) {};
};

int N, M;
int maximum = 2000000000;
int graph[50][50];
int dist[100][15];
vector<Pair> h,chi;
bool isopen[13];

bool oob(int n) {
    int cnt = 0;
    for (int j=0;j<chi.size();j++) {
        if (n%2) cnt++;
        n /= 2;
    }
    if (cnt > M) return true;
    return false;
}

void getDistance() {
    int sr, sc, er, ec;
    for (int i=0;i<h.size();i++) {
        for (int j=0;j<chi.size();j++) {
            sr = h[i].r; sc = h[i].c;
            er = chi[j].r; ec = chi[j].c;
            dist[i][j] = abs(sr-er) + abs(sc-ec);
        }
    }
}

void sol() {
    getDistance();

    int rep, ans, tmp, ox, cd;
    rep = 1; ans = maximum;
    for (int i=0;i<chi.size();i++) rep *= 2;

    for (int i=1;i<rep;i++) {
        if (oob(i)) continue;
        tmp = i; cd = 0;
        memset(isopen, false, sizeof(isopen));
        for (int j=0;j<chi.size();j++) {
            ox = tmp%2;
            tmp /= 2;
            if (ox) isopen[j] = true;
        }
        for (int hi=0;hi<h.size();hi++) {
            int mind = 1000;
            for (int j=0;j<chi.size();j++) {
                if (isopen[j])
                    mind = min(mind, dist[hi][j]);
            }
            cd += mind;
        } 
        ans = min(ans, cd);
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 1) h.push_back(Pair(i, j));
            else if (graph[i][j] == 2) chi.push_back(Pair(i, j));
        }
    }

    sol();
}