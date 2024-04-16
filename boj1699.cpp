#include <iostream>
#include <algorithm>

using namespace std;

int N, INF = 2e9;
int dp[100001];

void sol() {
    for (int i=1;i<=N;i++) dp[i] = INF;

    for (int i=1;i<=N;i++) {
        if (i*i > N) break;
        dp[i*i] = 1;
    }
    
    for (int i=2;i<=N;i++) {
        dp[i] = min(dp[i], dp[i-1] + 1);
        for (int j=2;j*j<i;j++) {
            dp[i] = min(dp[i], dp[i-(j*j)] + 1);
        }
    }

    cout << dp[N];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    sol();
}