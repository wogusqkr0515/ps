#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[101][10];

void dp() {
    arr[1][0] = 0;
    for (int i=1;i<10;i++) {
        arr[1][i] = 1;
    }

    for (int i=2;i<=N;i++) {
        for (int j=0;j<10;j++) {
            if (j != 0) arr[i][j] += arr[i-1][j-1];
            if (j != 9) arr[i][j] += arr[i-1][j+1];
            arr[i][j] %= 1000000000;
        }
    }

    int ans= 0;
    for (int i=0;i<10;i++) {
        ans = (ans + arr[N][i]) % 1000000000;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    dp();
}