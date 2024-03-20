#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int maxCoin = 1000000;
int coins[105];
int answer[10005];

void dp() {
    for (int i=1;i<=K;i++) answer[i] = maxCoin;

    for (int i=0;i<N;i++) {
        int coin = coins[i];
        for (int j=coin;j<=K;j++) {
            answer[j] = min(answer[j], answer[j-coin] + 1);
        }
    }

    if (answer[K] == maxCoin) cout << -1;
    else cout << answer[K];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i=0;i<N;i++)
        cin >> coins[i];

    dp();
}