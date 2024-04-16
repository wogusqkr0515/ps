#include <iostream>
#include <algorithm>

using namespace std;

int N, INF = 1e9;
int dp[100001][3], arr[100001][3];

void sol(int idx) {
    dp[0][0] = arr[0][1]; dp[0][1] = arr[0][1]; dp[0][2] = arr[0][1] + arr[0][2];

    for (int i=1;i<N;i++) {
        dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + arr[i][0];
        dp[i][1] = min(*min_element(dp[i-1], dp[i-1]+3), dp[i][0]) + arr[i][1];
        dp[i][2] = min(min(dp[i-1][1], dp[i-1][2]), dp[i][1]) + arr[i][2];
    }

    cout << idx << ". " << dp[N-1][1] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int idx =  1;
    while (true) {
        cin >> N;
        if (N==0) break;
        for (int i=0;i<N;i++) {
            cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
            dp[i][0]=INF; dp[i][1]=INF; dp[i][2]=INF;
        }

        sol(idx++);
    }
}