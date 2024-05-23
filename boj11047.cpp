#include <iostream>

using namespace std;

int N, K, coins[10];

void sol() {
    int target = K;
    int cnt = 0;

    for (int i=N-1;i>=0;i--) {
        if (coins[i] > K) continue;
        cnt += (target/coins[i]);
        target %= coins[i];

        if (!target) {
            cout << cnt;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i=0;i<N;i++) {
        cin >> coins[i];
    }

    sol();
}