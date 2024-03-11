#include <iostream>
#include <algorithm>

using namespace std;

int N;
int cost[1001][3];
int arr[1001][3];

void dp() {
    arr[0][0] = cost[0][0];
    arr[0][1] = cost[0][1];
    arr[0][2] = cost[0][2];

    for (int i=1;i<N;i++) {
        arr[i][0] = min(arr[i-1][1], arr[i-1][2]) + cost[i][0];
        arr[i][1] = min(arr[i-1][0], arr[i-1][2]) + cost[i][1];
        arr[i][2] = min(arr[i-1][0], arr[i-1][1]) + cost[i][2];
    }

    cout << min({arr[N-1][0], arr[N-1][1], arr[N-1][2]});
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    dp();
}