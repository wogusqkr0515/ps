#include <iostream>
#include <algorithm>

using namespace std;

int N,S, idx=-1, INF = 2e9;
int arr[100000], dp[100001];

void sol() {
    if (idx == -1) {
        cout << 0;
        return;
    }

    int ans = INF;
    int lidx = idx-1, ridx = idx; 

    while (true) {
        if (dp[ridx] - dp[lidx] >= S) {
            ans = min(ans, ridx-lidx);
            break;
        }
        lidx--;
    }
    
    while (ridx <= N) {
        while (dp[ridx] - dp[lidx+1] >= S) lidx++;
        ans = min(ans, ridx-lidx);
        ridx++; lidx++;
    }

    if (ans == INF) cout << 0;
    else cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;
    for (int i=0;i<N;i++) {
        cin >> arr[i];
        dp[i+1] = dp[i] + arr[i];
        if (dp[i+1] >= S && idx==-1) idx=i+1;
    }

    sol();
}