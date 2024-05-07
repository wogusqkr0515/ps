#include <iostream>
#include <algorithm>

using namespace std;

int N, arr[1000], dp[1001];

void sol() {
    int ans = 0;
    for (int i=0;i<N;i++) dp[i] = 1;

    for (int i=0;i<N;i++) {
        for (int j=0;j<i;j++) {
            if (arr[j] > arr[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    } 

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }

    sol();
}