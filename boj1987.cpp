#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int R,C, ans = 0;
string arr[20];
bool isvisit[26];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int row, int col, int step) {
    ans = max(ans, step);

    for (int i=0;i<4;i++) {
        int nr, nc;
        nr = row + dy[i]; nc = col + dx[i];
        if (nr>=0 && nc>=0 && nr<R && nc<C) {
            if (isvisit[arr[nr][nc] - 'A']) continue;
            isvisit[arr[nr][nc] - 'A'] = true;
            dfs(nr, nc, step+1);
            isvisit[arr[nr][nc] - 'A'] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;
    for (int i=0;i<R;i++) 
        cin >> arr[i];
    
    fill(isvisit, isvisit + 27, false);
    isvisit[arr[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    cout << ans;
}