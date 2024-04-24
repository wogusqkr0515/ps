#include <iostream>
#include <algorithm>

using namespace std;


int N,INF =2e9+4e8;
int row[501], col[501];
int dp[501][501];

void sol() {
    for (int i=1;i<N;i++) {
        for (int j=1;i+j<=N;j++) {
            dp[j][i+j] = INF;
            for (int k=j;k<i+j;k++) {
                dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k+1][i+j] + row[j] * col[k] * col[i+j]);
            }
        }
    }

    cout << dp[1][N];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=1;i<=N;i++) {
        cin >> row[i] >> col[i];
    }
    
    sol();
}
