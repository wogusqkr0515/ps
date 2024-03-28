#include <iostream>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int N, K;
int dp[102][100005];
pair<int, int> li[102];

void sol() {
    for (int j=1;j<=K;j++) {
        for (int i=1;i<=N;i++) {
            if (li[i].X > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-li[i].X] + li[i].Y);            
        }
    }   

    cout << dp[N][K];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> N >> K;
    for (int i=1;i<=N;i++) {
        cin >> a >> b;
        li[i] = {a, b}; 
    }
    
    sol();
}