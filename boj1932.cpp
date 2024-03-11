#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int tri[501][501];
int arr[501][501];

void dp() {
    arr[1][1] = tri[1][1];
    arr[2][1] = tri[1][1] + tri[2][1];
    arr[2][2] = tri[1][1] + tri[2][2];

    for (int i=3;i<=N;i++) {
        for (int j=1;j<i+1;j++) {
            arr[i][j] = max(arr[i-1][j-1], arr[i-1][j]) + tri[i][j];
        }
    }

    int ans = 0;
    for (int i=1;i<=N;i++) {
        ans = max(ans, arr[N][i]);
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(tri, 0, sizeof(tri));
    memset(arr, 0, sizeof(arr));

    cin >> N;
    for (int i=1;i<=N;i++) {
        for (int j=1;j<i+1;j++) {
            cin >> tri[i][j];
        }
    }

    dp();
}