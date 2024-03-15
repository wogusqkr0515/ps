#include <iostream>
#include <algorithm>

using namespace std;

int N;
int inp[1005];
int arr[1005];

void dp() {
    arr[0] = 0;

    for (int i=2;i<=N;i++) {
        for (int j=1;j<i;j++) {
            if (inp[j] < inp[i]) arr[i] = max(arr[i], arr[j]+1);
        }
    }

    cout << *max_element(arr+1, arr+N+1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=1;i<=N;i++) {
        cin >> inp[i];
        arr[i] = 1;
    }

    dp();
}