#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,K, ans = 2e9;
int board[11][11];

void sol() {
    vector<int> perm;
    for (int i=0;i<N;i++) {
        if (i==K) continue;
        perm.push_back(i);
    }

    for (int k=0;k<N;k++) {
        for (int i=0;i<N;i++) {
            for (int j=0;j<N;j++) {
                if (i==j) continue;
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
            }
        }
    }

    do {
        int step = board[K][perm[0]];
        for (int i=1;i<perm.size();i++) {
            step += board[perm[i-1]][perm[i]];
        }
        ans = min(ans, step);
    } while(next_permutation(perm.begin(), perm.end()));

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i=0;i<N;i++) 
        for (int j=0;j<N;j++) 
            cin >> board[i][j];
        
    sol();
}