#include <iostream>
#include <algorithm>

using namespace std;

int N, dp[50];

int fibo(int num) {
    if (num == 0) return 0;
    if (num == 1) return 1;
    if (num == 2) return 1;

    if (dp[num] != -1) return dp[num];
    dp[num] = fibo(num-1) + fibo(num-2);

    return dp[num];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    fill(dp, dp+49, -1);

    cout << fibo(N);
}