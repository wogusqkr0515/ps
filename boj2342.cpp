#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100000], i;
int dp[100001][5][5];
int cost[5][5] = {
    {0, 2, 2, 2, 2},
    {0, 1, 3, 4, 3},
    {0, 3, 1, 3, 4},
    {0, 4, 3, 1, 3},
    {0, 3, 4, 3, 1}
};

int func(int idx, int l, int r) {
    if (idx == i) return 0;

    int& ret = dp[idx][l][r];
    if (ret) return ret;

    ret = 1e9;
    if (arr[idx] != r) ret = min(ret, func(idx+1, arr[idx], r) + cost[l][arr[idx]]);
    if (arr[idx] != l) ret = min(ret, func(idx+1, l, arr[idx]) + cost[r][arr[idx]]);

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int val;
    for (i=0; ;i++) {
        cin >> val;
        if (val) arr[i] = val;
        else break;
    }

    cout << func(0, 0, 0);
}