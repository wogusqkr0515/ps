#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int coins[101];
int answer[10001];

void dp() {
    answer[0] = 1;
    for (int i=0;i<N;i++) {
        for (int j=coins[i];j<=K;j++) {
            answer[j] = answer[j] + answer[j-coins[i]];
        }
    }
    cout << answer[K];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> N >> K;
    for (int i=0;i<N;i++)
        cin >> coins[i];
    
    dp();
}