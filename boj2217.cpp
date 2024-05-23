#include <iostream>
#include <algorithm>

using namespace std;

int N, arr[100000];

void sol() {
    sort(arr, arr+N, greater<int>());
    int ans = 0;

    for (int i=0;i<N;i++) 
        ans = max(ans, arr[i] * (i+1));

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }

    sol();
}