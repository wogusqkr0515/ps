#include <iostream>
#include <algorithm>

using namespace std;

int N, a[50], b[50];

void sol() {
    sort(a, a+N, less<int>());
    sort(b, b+N, greater<int>());

    int ans = 0;
    for (int i=0;i<N;i++) {
        ans += (a[i]*b[i]);
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=0;i<N;i++)
        cin >> a[i];
    for (int i=0;i<N;i++)
        cin >> b[i];

    sol();
}