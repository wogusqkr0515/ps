#include <iostream>
#include <algorithm>

using namespace std;

int N, doneBit, INF = 2e9;
int arr[16][16];
int dp[16][(1<<16)+1];

int dfs(int cur, int status) {
    if (status == doneBit) {
        if (!arr[cur][0]) return INF;
        return arr[cur][0];
    }

    if (dp[cur][status] != -1) return dp[cur][status];
    dp[cur][status] = INF;

    for (int i=0;i<N;i++) {
        if (!arr[cur][i]) continue;
        if (status & (1<<i)) continue;

        dp[cur][status] = min(dp[cur][status], arr[cur][i] + dfs(i, status | (1<<i)));
    }

    return dp[cur][status];
}

void sol() {
    fill(&dp[0][0], &dp[N-1][(1<<N)], -1);
    doneBit = (1<<N)-1;

    cout << dfs(0,1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            cin >> arr[i][j];
        }
    }
    
    sol();
}