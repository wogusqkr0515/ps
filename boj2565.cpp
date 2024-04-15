#include <iostream>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int N;
int dp[100];
pair<int,int> arr[100];

void sol() {
    int ans = 0;
    sort(arr, arr+N);

    for (int i=0;i<N;i++) dp[i] = 1;
    for (int i=0;i<N;i++) {
        for (int j=0;j<i;j++) {
            if (arr[i].Y > arr[j].Y) dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }

    cout << N-ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b;
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> a >> b;
        arr[i] = {a,b};
    }

    sol();
}