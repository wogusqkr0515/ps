#include <iostream>
#include <algorithm>

using namespace std;

int T, N, INF = 2e9;
int arr[501], sums[501], dp[501][501];

void sol() {
    for (int i=1;i<=N;i++) {
        sums[i] = sums[i-1] + arr[i];
        for (int j=1;j<=N;j++) {
            dp[i][j] = 0;
        }
    }

    for (int i=1;i<N;i++) {
        for (int j=1;i+j<=N;j++) {
            dp[j][i+j] = INF;
            for (int k=j;k<i+j;k++) {
                dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k+1][i+j] + sums[i+j] - sums[j-1]);
            }
        }
    }

    cout << dp[1][N] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for (int i=0;i<T;i++) {
        cin >> N;
        for (int j=1;j<=N;j++) 
            cin >> arr[j];

        sol();
    }
}