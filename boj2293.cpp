#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
// int coins[105];
int answer[101][10001];

bool cmp (int a, int b) {
    return a > b;
}

int isDiv(int num, int idx) {
    if (num == 0) return 1;
    int ans = 0;

    for (int i=idx;i<N;i++) {
        for (int j=num;j>0;j--) {
            if (answer[i][j] > 0) {
                num -= (answer[i][j] * answer[i][0]);
                ans += isDiv(num, i+1);
                num += (answer[i][j] * answer[i][0]);
            }
        }
    }
    return ans;
}

void dp() {
    int ans = 0;
    for (int i=0;i<N;i++) {
        for (int j=1;j<=K;j++) {
            // if (j % coins[i] == 0) answer[i][j] = j / coins[i];
            if (j % answer[i][0] == 0) answer[i][j] = j / answer[i][0];
        }
    }
    
    ans += isDiv(K, 0);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;
    int n;
    cin >> N >> K;
    for (int i=0;i<N;i++) {
        // cin >> coins[i];
        cin >> n;
        v.push_back(n);
    }
    
    // sort(coins, coins + N, cmp);
    sort(v.begin(), v.end(), cmp);
    for (int i=0;i<N;i++)
        answer[i][0] = v[i];

    dp();
}