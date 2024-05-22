#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, K, mod = 1'000'000'000;
int d[201][201];

int dp(int num, int cnt) {
    if (num == 0 && cnt == K) return 1;
    if (cnt >= K) return 0;
    if (num <= 0) return 0;

    if (d[num][K-cnt] != -1) return d[num][K-cnt];

    int &ret = d[num][K-cnt];
    ret = 0;

    for (int i=0;i<=N;i++) {
        ret += dp(num-i, cnt+1);
        ret %= mod;
    }
    return ret;
}

void sol() {
    int ans = 0;
    memset(d, -1, sizeof(d));

    dp(N, 0);
    for (int i=0;i<=K;i++) {
        if (d[N][i] > 0) ans += d[N][i];
        ans %= mod;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    sol();
}