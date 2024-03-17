#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 세로 가로 스티커
int N, M, K; 
int graph[40][40];
vector<vector<int>> sticker[100][4];
vector<vector<int>> rs;
vector<int> iter;

bool marking(int row, int col, int idx, int rot) {
    bool flag = true;
    int sr, sc, nr, nc;
    sr = sticker[idx][rot].size(); sc = sticker[idx][rot][0].size();

    for (int y=0;y<sr;y++) {
        nr = row + y;
        if (nr > N-1) flag = false;
        if (!flag) break;
        for (int x=0;x<sc;x++) {
            nc = col + x;
            if (nc > M - 1) flag = false;
            if (!flag) break;
            if (sticker[idx][rot][y][x] == 1) {
                if (graph[nr][nc] > 0) flag = false;
            }
        }
    }

    if (!flag)
        return false;

    for (int y=0;y<sr;y++) {
        nr = row + y;
        for (int x=0;x<sc;x++) {
            nc = col + x;
            if (sticker[idx][rot][y][x] == 1) {
                graph[nr][nc] = idx+1;
            }
        }
    }
    return true;
}

bool check(int idx, int rot) {
    for (int y=0;y<N;y++) {
        for (int x=0;x<M;x++) {
            if (marking(y, x, idx, rot)) return true;
        }
    }
    return false;
}

void rotation(int idx, int rot) {
    rs.clear();
    int sr, sc;
    sr = sticker[idx][0].size(); sc = sticker[idx][0][0].size();
    
    if (rot == 1) {
        for (int y=0;y<sc;y++) {
            iter.clear();
            for (int x=sr-1;x>=0;x--) {
                iter.push_back(sticker[idx][0][x][y]);
            }
            rs.push_back(iter);
        }
        sticker[idx][rot] = rs;
    }

    else if (rot == 2) {
        for (int y=sr-1;y>=0;y--) {
            iter.clear();
            for (int x=sc-1;x>=0;x--) {
                iter.push_back(sticker[idx][0][y][x]);
            }
            rs.push_back(iter);
        }
        sticker[idx][rot] = rs;
    }

    else {
        for (int y=sc-1;y>=0;y--) {
            iter.clear();
            for (int x=0;x<sr;x++) {
                iter.push_back(sticker[idx][0][x][y]);
            }
            rs.push_back(iter);
        }
        sticker[idx][rot] = rs;
    }
}

void sol() {
    int ans = 0;

    for (int i=0;i<K;i++) {
        for (int j=1;j<4;j++) {
            rotation(i, j);
        }
    }

    for (int i=0;i<K;i++) {
        for (int j=0;j<4;j++) {
            if (check(i, j)) break;
        }
    }

    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            if (graph[i][j] > 0) ans++;
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i=0;i<K;i++) {
        int r, c, n;
        rs.clear();
        cin >> r >> c;
        for (int j=0;j<r;j++) {
            iter.clear();
            for (int x=0;x<c;x++) {
                cin >>n;
                iter.push_back(n);
            }
            rs.push_back(iter);
        }
        sticker[i][0] = rs;
    }

    sol();
}