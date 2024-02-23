// 아이템줍기 LV3

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int graph[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int ans = 987654321;

// struct Pair {
//     int r, c;
//     Pair(int row, int col): r(row), c(col) {};
// };

// int bfs (int row, int col, int tr, int tc) {
//     int cnt = -1;
//     queue<Pair> q;
//     q.push(Pair(row, col));
//     graph[row][col] = 0;
    
//     while (!q.empty()) {
//         int curR, curC;
//         curR = q.front().r; curC = q.front().c; q.pop();
//         cnt++;
//         if (curR == tr && curC == tc) break;
//         for (int i=0;i<4;i++) {
//             int nextR, nextC;
//             nextR = curR + dy[i]; nextC = curC + dx[i];
//             if (graph[nextR][nextC] == 1) {
//                 q.push(Pair(nextR, nextC));
//                 graph[nextR][nextC] = 0;
//                 break;
//             }
//         }
//     }
//     return cnt;
// }

void dfs(int row, int col, int tr, int tc, int cnt) {
    if (row == tr && col == tc) {
        ans = min(ans, cnt);
        return ;
    }
    
    for (int i=0;i<4;i++) {
        int nextR, nextC;
        nextR = row + dy[i]; nextC = col + dx[i];
        if (graph[nextR][nextC] == 1) {
            graph[nextR][nextC] = 0;
            dfs(nextR, nextC, tr, tc, cnt+1);
            graph[nextR][nextC] = 1;
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    characterX *= 2; characterY *= 2; itemX *= 2; itemY *= 2;
    for (vector<int> &iter : rectangle) {
        for (int i=0;i<4;i++) {
            iter[i] *= 2;
        }
    }
    
    // for (vector<int> &iter : rectangle) {
    //     for (int i=0;i<4;i++) {
    //         cout << iter[i] << " " ;
    //     }
    //     cout << endl;
    // }
    
    for (vector<int> iter : rectangle) {
        for (int i=iter[1];i<=iter[3];i++) {
            for (int j=iter[0];j<=iter[2];j++) {
                graph[i][j] = 1;
            }
        }
    }
    for (vector<int> iter : rectangle) {
        for (int i=iter[1]+1;i<iter[3];i++) {
            for (int j=iter[0]+1;j<iter[2];j++) {
                graph[i][j] = 0;
            }
        }
    }
    
    // for (int i=0;i<30;i++) {
    //     for (int j=0;j<30;j++) {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    // answer = bfs(characterY, characterX, itemY, itemX);
    dfs(characterY, characterX, itemY, itemX, 0);
    answer = (ans+1)/2;
    cout << answer << endl;
    
    
    
    return answer;
}