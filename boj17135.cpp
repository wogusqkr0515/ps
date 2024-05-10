#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int N,M,D,cnt, ans = 0, lastRow=100;
int board[20][20], board2[20][20];
int dx[3] = {-1, 0, 1};
int dy[3] = {0, -1, 0};
int coords[3];

void copy() {
    for (int i=0;i<N;i++) 
        for (int j=0;j<M;j++)
            board2[i][j] = board[i][j];
}

void move() {
    for (int i=N-1;i>0;i--) 
        for (int j=0;j<M;j++)
            board2[i][j] = board2[i-1][j];

    for (int j=0;j<M;j++) board2[0][j] = 0;
}

void bfs() {
    queue<pair<int,int>> removes;
    queue<tuple<int,int,int>> q;
    bool chk[3][20][20] = {false,};

    for (int i=0;i<3;i++) {
        q.push({N-1, coords[i], 1});
        chk[i][N-1][coords[i]] = true;

        while (!q.empty()) {
            int cr, cc, d;
            tie(cr,cc,d) = q.front(); q.pop();

            if (d == D+1) {
                while (!q.empty()) q.pop();
                break;
            }

            if (board2[cr][cc]) {
                removes.push({cr,cc});
                while (!q.empty()) q.pop();
                break;
            }

            for (int j=0;j<3;j++) {
                int nr, nc;
                nr = cr + dy[j]; nc = cc + dx[j];
                if (nr>=0 && nc>=0 && nc<M && !chk[i][nr][nc]) {
                    chk[i][nr][nc] = true;
                    q.push({nr,nc,d+1});
                }
            }
        }
    }

    while (!removes.empty()) {
        auto coord = removes.front(); removes.pop();
        if (board2[coord.X][coord.Y]) cnt++;
        board2[coord.X][coord.Y] = 0;
    }
}

void sol() {
    vector<int> v;
    for (int i=0;i<M;i++) {
        if (i<3) v.push_back(0);
        else v.push_back(1);
    }

    do {
        cnt = 0;
        copy();
        int j = 0;
        for (int i=0;i<M;i++) {
            if (!v[i]) coords[j++] = i;
            if (j == 3) break;
        }
        
        for (int idx=0;idx<N-lastRow;idx++) {
            bfs();
            move();
        }
        ans = max(ans, cnt);
    } while(next_permutation(v.begin(), v.end()));

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> D;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            cin >> board[i][j];
            if (board[i][j] && lastRow>20) lastRow = i;
        }
    }

    sol();
}