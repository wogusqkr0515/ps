#include <iostream>
#include <algorithm>

using namespace std;

int ans = 0x7fffffff, remain=0;
int board[10][10];
int cnt[6];

void draw(int r, int c, int size) {
    cnt[size]++;
    remain -= size*size;

    for (int i=r;i<r+size;i++) {
        for (int j=c;j<c+size;j++) {
            board[i][j] = 0;
        }
    }
}

void clean(int r, int c, int size) {
    cnt[size]--;
    remain += size*size;

    for (int i=r;i<r+size;i++) {
        for (int j=c;j<c+size;j++) {
            board[i][j] = 1;
        }
    }
}

bool chkSize(int r, int c, int size) {
    if (cnt[size] == 5) return false;
    if (r+size>10 || c+size>10) return false;

    for (int i=r;i<r+size;i++) {
        for (int j=c;j<c+size;j++) {
            if (!board[i][j]) return false;
        }
    }

    return true;
}

void dfs(int r, int c, int use) {
    if (!remain) {
        ans = min(ans, use);
        return;
    }

    for (int i=r;i<10;i++) {
        for (int j=c;j<10;j++) {
            if (!board[i][j]) continue;
            for (int k=5;k>0;k--) {
                if (chkSize(i,j,k)) {
                    draw(i,j,k);
                    dfs(i,j+k, use+1);
                    clean(i,j,k);
                }
            }
            return;
        }
        c=0;
    }
} 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i=0;i<10;i++) {
        for (int j=0;j<10;j++) {
            cin >> board[i][j];
            if (board[i][j]) remain++;
        }
    }

    dfs(0,0, 0);
    
    if (ans == 0x7fffffff) cout << -1;
    else cout << ans;
}