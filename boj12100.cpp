#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int repeat = 5;
int N;
int board[20][20];
int board2[20][20];
// 동 남 서 북 순서  -> 미는 순서는 우에서 좌, 밑에서 위로, 좌에서 우, 위에서 밑으로
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ans = 0;

bool oob(int idx) {
    if (idx >= 0 && idx < N) return false;
    return true;
}

void move(int dir, int tt) {
    int idx, pre, pi;

    if (dir % 2 == 0) {
        for (int i=0;i<N;i++) {
            if (dir==0) idx = 0;
            else idx = N-1;
            pre = 0; pi = -1;
            while (true) {
                if (oob(idx)) break;
                if (board2[i][idx] > 0) {
                    if (board2[i][idx] == pre) {
                        board2[i][idx] += pre;
                        board2[i][pi] = 0;
                        pre = 0;
                    }
                    else {
                        pre = board2[i][idx];
                        pi = idx;
                    }
                    ans = max(ans, board2[i][idx]);
                }
                idx += dx[dir];
            }
            if (dir==0) idx = 0;
            else idx = N-1;
            pi = -1;
            while (true) {
                if (oob(idx)) break;
                if (board2[i][idx] == 0 && pi == -1) pi = idx;
                if (board2[i][idx] > 0 && pi != -1) {
                    board2[i][pi] = board2[i][idx];
                    board2[i][idx] = 0;
                    pi+= dx[dir];
                }
                idx += dx[dir];
            }
        }
    } else {
        for (int j=0;j<N;j++) {
            if (dir==1) idx = 0;
            else idx = N-1;
            pre = 0; pi = -1;
            while (true) {
                if (oob(idx)) break;
                if (board2[idx][j] > 0) {
                    if (board2[idx][j] == pre) {
                        board2[idx][j] += pre;
                        board2[pi][j] = 0;
                        pre = 0;
                    }
                    else {
                        pre = board2[idx][j];
                        pi = idx;
                    }
                    ans = max(ans, board2[idx][j]);
                }
                idx += dy[dir];
            }
            if (dir==1) idx = 0;
            else idx = N-1;
            pi = -1;
            while (true) {
                if (oob(idx)) break;
                if (board2[idx][j] == 0 && pi == -1) pi = idx;
                if (board2[idx][j] > 0 && pi != -1) {
                    board2[pi][j] = board2[idx][j];
                    board2[idx][j] = 0;
                    pi+= dy[dir];
                }
                idx += dy[dir];
            }
        }
    }
}

void copy12() {
    for (int i=0;i<N;i++) 
        for (int j=0;j<N;j++)
            board2[i][j] = board[i][j];
}

void printboard() {
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            cout << board2[i][j];
            if (board2[i][j] > 100) cout << " ";
            else if (board2[i][j] > 10) cout << "  ";
            else  cout << "   ";
        }
        cout << endl;
    }
}

void sol() {
    if (N==1) {
        cout << board[0][0];
        return;
    }

    for (int i=0;i<1024;i++) {
        copy12();

        int tmp = i;
        for (int j=0;j<repeat;j++) {
            int dir = tmp % 4;
            tmp /= 4;
            move(dir, i);
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            cin >> board[i][j];
        }
    }

    sol();
}