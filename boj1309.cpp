#include <iostream>

using namespace std;

int N, dp[100'001][3];

void sol() {
    dp[0][0] = 1;
    for (int i=1;i<=N;i++) {
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % 9901;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % 9901;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % 9901;
    }

    cout << (dp[N][0] + dp[N][1] + dp[N][2]) % 9901;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    sol();
}