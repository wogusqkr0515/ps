#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int nums[100001];
int snum[100001];

void dp(int i, int j) {
    cout << snum[j] - snum[i-1] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    snum[0] = 0;
    cin >> N >> M;
    for (int i=1;i<=N;i++) {
        cin >> nums[i];
        snum[i] = snum[i-1] + nums[i];
    }

    for (int i=0;i<M;i++) {
        int l,h;
        cin >> l >> h;
        dp(l, h);
    }
}