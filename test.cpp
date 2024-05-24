#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int N, K, dp[100'001][101];
pair<int, int> arr[101];

void sol() {
    for (int k=1;k<=K;k++) {
        for (int i=1;i<=N;i++) {
            dp[k][i] = max(dp[k][i], dp[k][i-1]);
            if (arr[i].X > k) continue;
            dp[k][i] = max(dp[k][i], dp[k-arr[i].X][i-1] + arr[i].Y);
        }
    }

    cout << dp[K][N];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i=1;i<=N;i++) {
        cin >> arr[i].X >> arr[i].Y;
    }

    sol();
}