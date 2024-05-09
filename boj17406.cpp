#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int N,M,K, ans = 2e9;
int board[51][51], board2[51][51];
int rcs[6][3];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


void copy() {
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=M;j++) {
            board2[i][j] = board[i][j];
        }
    }
}

bool oob(int row, int col, int lr, int hr, int lc, int hc) {
    return !(row>=lr && col>=lc && row<=hr && col<=hc);
}

void rotate(int idx) {
    int tmp[51][51];
    int lr, lc, hr, hc;
    lr = rcs[idx][0] - rcs[idx][2];
    hr = rcs[idx][0] + rcs[idx][2];
    lc = rcs[idx][1] - rcs[idx][2];
    hc = rcs[idx][1] + rcs[idx][2];

    for (int i=1;i<=N;i++) {
        for (int j=1;j<=M;j++) {
            if (oob(i,j,lr,hr,lc,hc)) tmp[i][j] = board2[i][j];
        }
    }

    int row, col, nr, nc, dir;
    while (lr<hr && lc<hc) {
        row = lr; col = lc; dir=0;
        while (dir<3 || row != lr || col != lc) {
            nr = row + dy[dir]; nc = col + dx[dir];
            if (oob(nr,nc, lr,hr,lc,hc)) {
                dir = (dir+1)%4;
                nr = row + dy[dir]; nc = col + dx[dir];
            }
            tmp[nr][nc] = board2[row][col];
            row = nr; col = nc;
        }
        lr++; hr--;
        lc++; hc--;
    }
    if (lr==hr || lc==hc) {
        for (int i=lr;i<=hr;i++) {
            for (int j=lc;j<=hc;j++) {
                tmp[i][j] = board2[i][j];
            }
        }
    }

    for (int i=1;i<=N;i++) {
        for (int j=1;j<=M;j++) {
            board2[i][j] = tmp[i][j];
        }
    }
}

void sol() {
    for (int i=0;i<K;i++) v.push_back(i);

    do {
        copy();
        for (int i=0;i<K;i++) {
            rotate(v[i]);
        }

        for (int i=1;i<=N;i++) {
            int sum = 0;
            for (int j=1;j<=M;j++) sum += board2[i][j];
            ans = min(ans, sum);
        }
    } while(next_permutation(v.begin(), v.end()));

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=M;j++) {
            cin >> board[i][j];
        }
    }

    for (int i=0;i<K;i++) {
        cin >> rcs[i][0] >> rcs[i][1] >> rcs[i][2];
    }

    sol();
}