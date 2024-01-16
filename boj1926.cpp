#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> arr, visited;
int row, col;
int rowDirec[4] = {0, 1, 0, -1};
int colDirec[4] = {1, 0, -1, 0};

int bfs(int r, int c) {
    queue<pair<int, int>> q;
    pair<int, int> current;
    int width = 0;
    q.push(make_pair(r,c));
    visited[r][c] = 1;
    while(!q.empty()) {
        current.first = q.front().first; current.second = q.front().second;
        q.pop(); width++;
        for (int i=0;i<4;i++) {
            int curRow, curCol;
            curRow = current.first+rowDirec[i]; curCol = current.second+colDirec[i];
            if (curRow>=0 && curRow<row && curCol>=0 && curCol<col) {
                if (visited[curRow][curCol] == 0 && arr[curRow][curCol] == 1) {
                    q.push(make_pair(curRow,curCol));
                    visited[curRow][curCol] = 1;
                }
            }
        }
    }
    return width;
}

int dfs(int r, int c, int width) {
    for (int i=0;i<4;i++) {
        int curRow, curCol;
        curRow = r+rowDirec[i]; curCol = c+colDirec[i];
        if (curRow>=0 && curRow<row && curCol>=0 && curCol<col) {
            if (visited[curRow][curCol] == 0 && arr[curRow][curCol] == 1) {
                visited[curRow][curCol] = 1;
                width = dfs(curRow, curCol, width+1);
            }
        }
    }
    return width;
}

int main() {
    vector<int> rowArr, zeroArr;
    int val, maxWidth, width, cnt;
    maxWidth = 0; cnt = 0;

    cin >> row >> col;
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            cin >> val;
            rowArr.push_back(val);
            if (i==0) zeroArr.push_back(0);
        }
        visited.push_back(zeroArr);
        arr.push_back(rowArr);
        rowArr.clear();
    }
    // bfs
    // for (int i=0; i<row; i++) {
    //     for (int j=0; j<col; j++) {
    //         if (visited[i][j] == 0 && arr[i][j] == 1) {
    //             width = bfs(i, j);
    //             cnt++;
    //             maxWidth = max(maxWidth, width);
    //         }
    //     }
    // }

    // dfs
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            if (visited[i][j] == 0 && arr[i][j] == 1) {
                visited[i][j] = 1;
                width = dfs(i, j, 1);
                cnt++;
                maxWidth = max(maxWidth, width);
            }
        }
    }
    cout << cnt << endl << maxWidth << endl;
}