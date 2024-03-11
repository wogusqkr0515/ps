#include <iostream>
#include <algorithm>

using namespace std;

int cnt[41][2];

void getCnt() {
    cnt[0][0] = 1; cnt[0][1] = 0;
    cnt[1][0] = 0; cnt[1][1] = 1;

    for (int i=2;i<=40;i++) {
        cnt[i][0] = cnt[i-1][0] + cnt[i-2][0];
        cnt[i][1] = cnt[i-1][1] + cnt[i-2][1];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    getCnt();

    int N;
    cin >> N;
    for (int i=0;i<N;i++) {
        int n;
        cin >> n;
        cout << cnt[n][0] << " " << cnt[n][1] <<'\n';
    }
}