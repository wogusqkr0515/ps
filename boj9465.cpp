#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int dp[100002][3];
vector<vector<vector<int>>> arr;

void sol() {
    for (int i=0;i<T;i++) {
        int n = arr[i][0].size();
        fill(&dp[0][0], &dp[n][2], 0);

        for (int j=1;j<=n;j++) {
            dp[j][0] = dp[j-1][1] + arr[i][0][j-1];
            dp[j][1] = dp[j-1][0] + arr[i][1][j-1];
            if (j>1) {
                dp[j][0] = max(dp[j][0], dp[j-2][1] + arr[i][0][j-1]);
                dp[j][1] = max(dp[j][1], dp[j-2][0] + arr[i][1][j-1]);
            }
        }
        cout << max(dp[n][0] , dp[n][1]) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, val;
    cin >> T;
    for (int i=0;i<T;i++) {
        vector<int> initer;
        vector<vector<int>> iter;
        cin >> n;
        for (int j=0;j<n;j++) {
            cin >> val;
            initer.push_back(val);
        }
        iter.push_back(initer);
        initer.clear();
        for (int j=0;j<n;j++) {
            cin >> val;
            initer.push_back(val);
        }
        iter.push_back(initer);
        arr.push_back(iter);
    }

    sol();
}