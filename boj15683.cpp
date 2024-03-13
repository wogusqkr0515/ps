#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair {
    int r, c;
    Pair(int row, int col): r(row), c(col) {};
};

int R, C;
int graph[8][8];
int mark[8][8];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<Pair> cctv;

bool oob(int r, int c) {
    if (r>=0 && c>=0 && r<R && c<C) return false;
    return true;
}

void check(int r, int c, int d) {
    while (true) {
        r += dy[d]; c += dx[d];
        if (oob(r, c)) return;
        if (mark[r][c] == 6) return;
        if (mark[r][c] == 0) mark[r][c] = 7;
    }
}

void sol() {
    int cnt, answer, p;
    answer = 2000000000; p = 1;
    
    for (int i=0;i<cctv.size();i++) p *= 4;
    if (p == 1) {
        answer = 0;
        for (int r=0;r<R;r++) {
            for (int c=0;c<C;c++) {
                if (graph[r][c] == 0) answer++;
            }
        }
        cout << answer;
        return;
    }
    // cout << "chk P " << p << endl;

    for (int i=0;i<p;i++) {
        // cout << "set mark" << endl;
        for (int r=0;r<R;r++) {
            for (int c=0;c<C;c++) {
                mark[r][c] = graph[r][c];
            }
        }
        // cout << "check cctv idx " << i << endl;
        int idx = i;
        for (int j=0;j<cctv.size();j++) {
            int x, y, dir;
            y = cctv[j].r; x = cctv[j].c;
            dir = idx%4;
            idx = idx / 4;

            switch (graph[y][x]) {
                case 1:
                    // cout << "chk cctv num" << endl;
                    check(y, x, dir);
                    break;
                case 2 :
                    if (dir>1) continue;
                    check(y, x, dir);
                    check(y, x, (dir+2)%4);
                    break;
                case 3 :
                    check(y, x, dir);
                    check(y, x, (dir+1)%4);
                    break;
                case 4 :
                    check(y, x, dir);
                    check(y, x, (dir+1)%4);
                    check(y, x, (dir+2)%4);
                    break;
                case 5 :
                    if (dir > 0) continue;
                    check(y, x, dir);
                    check(y, x, (dir+1)%4);
                    check(y, x, (dir+2)%4);
                    check(y, x, (dir+3)%4);
                    break;
            }
        }

        cnt = 0;
        for (int r=0;r<R;r++) {
            for (int c=0;c<C;c++) {
                if (mark[r][c] == 0) cnt++;
                // cout << mark[r][c];
            }
            // cout << endl;
        }
        answer = min(answer, cnt);
        // cout << answer << endl;
    }

    cout << answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;
    for (int i=0;i<R;i++) {
        for (int j=0;j<C;j++) {
            cin >> graph[i][j];
            if (graph[i][j] > 0 && graph[i][j] < 6) cctv.push_back(Pair(i, j));
        }
    }

    sol();
}