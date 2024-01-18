#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, N;
vector<vector<vector<int>>> visited, arr;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

struct Pair {
    int r, c;
    Pair(int row, int col): r(row), c(col) {};
};

void bfs(int i, int r, int c) {
    queue<Pair> q;
    q.push(Pair(r,c));

    while(!q.empty()) {
        int curR, curC;
        curR = q.front().r; curC= q.front().c; q.pop();
        for (int k = 0;k<4;k++) {
            int nextR, nextC;
            nextR = curR + dx[k]; nextC = curC + dy[k];
            if (nextR > -1 && nextR < arr[i].size() && nextC > -1 && nextC < arr[i][0].size()) {
                if (arr[i][nextR][nextC] == 1 && visited[i][nextR][nextC] == 0) {
                    q.push(Pair(nextR,nextC));
                    visited[i][nextR][nextC] = 1;
                }
            }
        }
    }
}

int main() {
    int T, k, r,c;
    vector<int> iter, answer;
    vector<vector<int>> visitIter, arrIter;
    
    cin >> T;
    for (int z=0;z<T;z++) {
        cin >> M >> N >> k;
        
        for (int i=0;i<N;i++) {
            if (i==0) {
                for (int j=0;j<M;j++) {
                    iter.push_back(0);
                }
            }
            visitIter.push_back(iter);
            arrIter.push_back(iter);
        }
        for (int x=0;x<k;x++) {
            cin >> c >> r;
            arrIter[r][c] = 1;
        }

        visited.push_back(visitIter);
        arr.push_back(arrIter);
        visitIter.clear();
        arrIter.clear();
        iter.clear();
    }
    // cout << "test code  " << endl;
    for (int i=0;i<T;i++) {
        int cnt = 0;
        for (int j=0;j<arr[i].size();j++) {
            for (int k=0;k<arr[i][0].size();k++) {
                if (visited[i][j][k] == 0 && arr[i][j][k] == 1) {
                    bfs(i, j, k);
                    cnt++;
                    // cout << "I = " << i << cnt << endl;
                }
            }
        }
        answer.push_back(cnt);
    }
    // cout << endl;
    for (int i=0;i<T;i++) {
        cout << answer[i] << endl;
    }
}