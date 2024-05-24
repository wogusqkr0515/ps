#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
#define X first
#define Y second

int N, M, T, board[100][100];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool isvisit[2][100][100];

void sol() {
    queue<tuple<int,int,int,int>> q;
    memset(isvisit, false, sizeof(isvisit));

    q.push({0,0,0,0});

    while (!q.empty()) {
        int cr,cc,time,floor;
        tie(cr,cc,time,floor) = q.front(); q.pop();
        if (time > T) {
            cout << "Fail";
            return;
        }
        if (cr==N-1 && cc==M-1) {
            cout << time;
            return;
        }

        for (int i=0;i<4;i++) {
            int nr,nc;
            nr = cr+dy[i]; nc = cc+dx[i];
            if (!(nr>=0 && nc>=0 && nr<N && nc<M)) continue;
            if (isvisit[floor][nr][nc]) continue;
            if (!floor && board[nr][nc] == 1) continue;
            if (board[nr][nc] == 2) {
                isvisit[floor][nr][nc] = true;
                floor = 1;
            }

            isvisit[floor][nr][nc] = true;
            q.push({nr,nc,time+1,floor});
        }
    }

    cout << "Fail";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> T;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            cin >> board[i][j];
        }
    }

    sol();
}