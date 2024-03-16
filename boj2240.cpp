#include <iostream>
#include <algorithm>

using namespace std;

int T, W;
int tree[1010];
int jadoo[31][3][1010];

void dp() {
    int ans = 0;
    jadoo[0][1][0] = 0; jadoo[0][2][0] = 0;
    for (int i=0;i<=W;i++) {
        for (int j=1;j<=T;j++) {
            if (i==0) {
                jadoo[i][1][j] = jadoo[i][1][j-1];
                jadoo[i][2][j] = jadoo[i][2][j-1];
                jadoo[i][tree[j]][j] += 1;
                if (j==1) jadoo[i][2][1] = 0;
            }
            else {
                if (tree[j] == 1) {
                    jadoo[i][1][j] = max(jadoo[i-1][2][j-1]+1, jadoo[i][1][j-1]+1);
                    jadoo[i][2][j] = max(jadoo[i-1][1][j-1], jadoo[i][2][j-1]);
                } else {
                    jadoo[i][1][j] = max(jadoo[i-1][2][j-1], jadoo[i][1][j-1]);
                    jadoo[i][2][j] = max(jadoo[i-1][1][j-1]+1, jadoo[i][2][j-1]+1);
                }
                
            }
            ans = max(ans, max(jadoo[i][1][j], jadoo[i][2][j]));
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T >> W;
    for (int i=1;i<=T;i++) {
        cin >> tree[i];
    }

    dp();
}