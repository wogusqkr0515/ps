#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1005], dp[1005];

void sol() {
    for (int i=1;i<=N;i++) {
        for (int j=1;j<i;j++) {
            dp[i] = max(dp[i], dp[i-j] + arr[j]);
        }
        dp[i] = max(dp[i], arr[i]);
    }

    cout << dp[N];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=1;i<=N;i++) cin >> arr[i];

    sol();
}