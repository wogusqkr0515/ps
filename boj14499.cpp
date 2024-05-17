#include <iostream>
#include <algorithm>

using namespace std;

int N,M,X,Y,K,board[20][20];
// 위, 동, 아래, 서, 북, 남
int dice[6];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

bool oob(int r, int c) {
    return !(r>=0 && c>=0 && r<N && c<M);
}

void sol(int dir) {
    int nr, nc;
    nr = X + dy[dir-1]; nc = Y + dx[dir-1];
    if (oob(nr, nc)) return;
    X = nr; Y = nc;

    int tmp;
    if (dir == 1) {
        tmp = dice[3];
        for (int i=2;i>=0;i--) {
            dice[i+1] = dice[i];
        }
        dice[0] = tmp;
    }
    else if (dir == 2) {
        tmp = dice[0];
        for (int i=0;i<3;i++) {
            dice[i] = dice[i+1];
        }
        dice[3] = tmp;
    }
    else if (dir == 3) {
        tmp = dice[0];
        
        dice[0] = dice[5];
        dice[5] = dice[2];
        dice[2] = dice[4];
        dice[4] = tmp;
    }
    else {
        tmp = dice[0];

        dice[0] = dice[4];
        dice[4] = dice[2];
        dice[2] = dice[5];
        dice[5] = tmp;
    }

    if (board[X][Y]) {
        dice[2] = board[X][Y];
        board[X][Y] = 0;
    } else {
        board[X][Y] = dice[2];
    }

    cout << dice[0] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> X >> Y >> K;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            cin >> board[i][j];
        }
    }

    dice[2] = board[X][Y];
    board[X][Y] = 0;

    int n;
    while (K--) {
        cin >> n;
        sol(n);
    }
}