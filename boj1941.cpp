#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

struct Pair {
    int r,c;
    Pair(int row, int col): r(row), c(col) {};
};

string graph[5];
int ans = 0;
int nums[7];
int visited[25] = {0,};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool isMoreFour() {
    int sum = 0;
    for (int i=0;i<7;i++) {
        int r,c, n;
        r = nums[i] / 5; c = nums[i] % 5;
        if (graph[r][c] == 'S') sum += 1;
    }
    if (sum>=4) return true;
    return false;
}

bool isAdjacency() {
    bool isSelected[5][5];
    bool isVisit[5][5];
    queue<Pair> q;
    int cnt = 0;

    memset(isSelected, false, sizeof(isSelected));
    memset(isVisit, false, sizeof(isVisit));

    for (int i=0;i<7;i++) {
        int r, c;
        r = nums[i] / 5; c = nums[i] % 5;
        isSelected[r][c] = true;
        if (i==0) {
            q.push(Pair(r, c));
            isVisit[r][c] = true;
        }
    }

    while (!q.empty()) {
        int cr, cc;
        cr = q.front().r; cc = q.front().c; q.pop();
        cnt++;
        for (int i=0;i<4;i++) {
            int nr, nc;
            nr = cr + dy[i]; nc = cc + dx[i];
            if (nr>=0 && nc>=0 && nr<5 && nc<5) {
                if (isSelected[nr][nc] && !isVisit[nr][nc]) {
                    isVisit[nr][nc] = true;
                    q.push(Pair(nr, nc));
                }
            }
        }
    }
    if (cnt == 7) return true;
    return false;
}

void getNum(int start , int depth) {
    if (depth == 7) {
        if (isMoreFour()) {
            if (isAdjacency()) ans++;
        }
        return;
    }

    for (int i=start;i<25;i++) {
        if (visited[i] == 0) {
            nums[depth] = i;
            visited[i] = 1;
            getNum(i+1, depth+1);
            visited[i] = 0;
        }
    }
}
  
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    
    string str;
    for (int i=0;i<5;i++) {
        cin >> str;
        graph[i] = str;
    }

    getNum(0, 0);

    cout << ans;
}