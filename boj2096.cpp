#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[6], tmp[6];
int board[100000][3];

void sol() {
    dp[0] = board[0][0]; dp[1] = board[0][1]; dp[2] = board[0][2];
    dp[3] = board[0][0]; dp[4] = board[0][1]; dp[5] = board[0][2];

    for (int i=1;i<N;i++) {
        for (int j=0;j<6;j++) tmp[j] = dp[j];
        
        dp[0] = max(tmp[0], tmp[1]) + board[i][0]; dp[3] = min(tmp[3], tmp[4]) + board[i][0];
        dp[1] = *max_element(tmp, tmp+3) + board[i][1]; dp[4] = *min_element(tmp+3, tmp+6) + board[i][1];
        dp[2] = max(tmp[1], tmp[2]) + board[i][2]; dp[5] = min(tmp[4], tmp[5]) + board[i][2];
    }

    cout << *max_element(dp, dp+3) << " " << *min_element(dp+3, dp+6);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> board[i][0] >> board[i][1] >> board[i][2];
    }
    
    sol();
}