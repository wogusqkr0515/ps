#include <iostream>

using namespace std;
typedef long long ll;

int N;
ll dp[100];

ll fibo(int num) {
    if (dp[num] != -1) return dp[num];

    ll &ret = dp[num];
    ret = 0;

    return ret = fibo(num-1) + fibo(num-2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    fill(dp, dp+99, -1);
    dp[0] = 0; dp[1] = 1;

    cout << fibo(N);
}