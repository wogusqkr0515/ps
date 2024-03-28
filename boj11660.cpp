#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int board[1025][1025];
int board2[1025][1025];

void sol(int r1, int c1, int r2, int c2) {
    int sum = 0;
    for (int i=r1;i<=r2;i++) {
        sum += (board2[i][c2] - board2[i][c1-1]);
    }
    cout << sum << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c,d;
    cin >> N >> M;
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            cin >> board[i][j];
            board2[i][j] = board2[i][j-1] + board[i][j];
        }
    }

    for (int i=0;i<M;i++) {
        cin >> a >> b >> c >> d;
        sol(a, b, c, d);
    }

}