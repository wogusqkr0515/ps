#include <iostream>
#include <algorithm>

using namespace std;

int T, N;
int target[15];
int coins[15][25];
int answer[10][10010];


void dp() {
    for (int i=0;i<T;i++) {
        int tar = target[i];
        answer[i][0] = 1;
        for (int j=1;j<=coins[i][0];j++) {
            int coin = coins[i][j];
            for (int idx=coin;idx<=tar;idx++) {
                answer[i][idx] = answer[i][idx] + answer[i][idx-coin];
            }
        }
        cout << answer[i][tar] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for (int i=0;i<T;i++) {
        cin >> coins[i][0];
        for (int j=1;j<=coins[i][0];j++) 
            cin >> coins[i][j];
        cin >> target[i];
    }

    dp();
}