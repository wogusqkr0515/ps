#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[11];

void dp() {
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for (int i=4;i<=10;i++) {
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    dp();
    cin >> N;
    for (int i=0;i<N;i++) {
        int val;
        cin >> val;
        cout << arr[val] << '\n';
    }
}