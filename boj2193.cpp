#include <iostream>
#include <algorithm>

using namespace std;

int N;
long long board[100][2];

void dp() {
    board[1][1] = 1;

    for (int i=2;i<=N;i++) {
        board[i][0] = board[i-1][0] + board[i-1][1];
        board[i][1] = board[i-1][0];
    }

    cout << board[N][0] + board[N][1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    dp();
}