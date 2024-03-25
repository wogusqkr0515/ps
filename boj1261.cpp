#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

struct Coord {
    int dist, r, c;
    Coord(int distance, int row, int col) : dist(distance), r(row), c(col) {};
};

struct cmp {
    bool operator() (const Coord& a, const Coord& b) {
        if (a.dist == b.dist) {
            if (a.r == b.r) return a.c > b.c;
            return a.r > b.r;
        }
        return a.dist > b.dist;
    }
};

int N,M;
int INF = 1e9;
int d[102][102];
string adj[102];
char one = '1';
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool oob(int r, int c) {
    if (r>=1 && c>=1 && r<N+1 && c<M+1) return false;
    return true;
}

void sol() {
    priority_queue<Coord,
                vector<Coord>,
                cmp> pq;
    
    fill(&d[0][0], &d[N+1][M+1], INF);

    pq.push(Coord(0, 1,1));
    d[1][1] = 0;

    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (cur.r == N && cur.c == M) break;
        
        if (d[cur.r][cur.c] != cur.dist) continue;
        for (int i=0;i<4;i++) {
            int nr, nc, nd;
            nr = cur.r + dy[i]; nc = cur.c + dx[i];
            if (oob(nr, nc)) continue;
            if (adj[nr-1][nc-1] == one) nd = cur.dist+1;
            else nd = cur.dist;
            if (d[nr][nc] <= nd) continue;
            pq.push(Coord(nd, nr, nc));
            d[nr][nc] = nd;
        }
    }

    cout << d[N][M];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;
    for (int i=0;i<N;i++) 
        cin >> adj[i];

    sol();    
}