#include <iostream>

using namespace std;

int T, N;
int nums[100001], state[100001];

void check(int x) {
    int cur = x;

    while (true) {
        state[cur] = x;
        cur = nums[cur];

        if (state[cur] == x) {
            while (state[cur] == x) {
                state[cur] = -1;
                cur = nums[cur];
            }
            break;
        }
        else if (state[cur] != 0) {
            break;
        }
    }
}

void sol() {
    int ans = 0;
    for (int i=1;i<=N;i++) {
        if (state[i]==0) check(i);
    }

    for (int i=1;i<=N;i++) if (state[i]>-1) ans++;

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for (int i=0;i<T;i++) {
        cin >> N;

        for (int j=1;j<=N;j++) {
            state[j] = 0;
            cin >> nums[j];
        }

        sol();
    }
}