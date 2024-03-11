#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1001];

void dp() {
    arr[1] = 1;
    arr[2] = 3;

    for (int i=3;i<=N;i++) {
        arr[i] = ( arr[i-1] + (arr[i-2] * 2) ) % 10007;
    }

    cout << arr[N];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    
    dp();
}