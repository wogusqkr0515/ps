#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int R,C;
vector<string> arr;  // 입력 미로
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct Coordinate {
    int r,c,m;
    Coordinate(int row, int col, int min): r(row), c(col), m(min) {};
};

int bfs() {
    queue<Coordinate> jq, fq; // 불, 지훈이 bfs 큐
    char J, F, can;
    // 문자를 변수로 선언
    J = 'J'; F = 'F'; can = '.';

    // 초기 위치 세팅
    for (int i=0;i<R;i++) {
        for (int j=0;j<C;j++) {
            if (arr[i][j] == J) jq.push(Coordinate(i,j,0));
            if (arr[i][j] == F) fq. push(Coordinate(i,j,0));
        }
    }

    int curJR, curJC, curJM, curFR, curFC, curFM;
    curJM = -1;

    while(!jq.empty() || !fq.empty()) {
        // 제일 처음 지훈이, 불 위치 및 시간 세팅
        if (curJM == -1) {
            // 지훈이는 반드시 하나 존재
            curJR = jq.front().r; curJC = jq.front().c; curJM = jq.front().m; jq.pop(); 
            // 처음 위치가 탈출 가능이면 바로 탈출
            if (curJR == 0 || curJC == 0 || curJR == R-1 || curJC == C-1) return curJM+1;
            // 불은 존재하지 않을 수도 있음
            if (!fq.empty()) { curFR = fq.front().r; curFC = fq.front().c; curFM = fq.front().m; fq.pop(); }
        }
        
        // 불 부터 bfs 
        // 불의 큐가 비워지기 전이거나 불의 시간이 지훈이 시간 다음이 될때까지
        do {
            for (int i=0;i<4;i++) {
                int nextFR, nextFC;
                nextFR = curFR + dx[i]; nextFC = curFC + dy[i];
                if (nextFR >=0 && nextFR <R && nextFC >=0 && nextFC < C) {
                    if (arr[nextFR][nextFC] == can) {
                        arr[nextFR][nextFC] = F;
                        fq.push(Coordinate(nextFR, nextFC, curFM+1));
                    }
                }
            }

            if (!fq.empty()) { curFR = fq.front().r; curFC = fq.front().c; curFM = fq.front().m; fq.pop(); }
            else { curFR = -10; curFC = -10; break;}
        } while(curJM == curFM);

        // 지훈이 bfs
        // 지훈이 큐가 비워지기 전이거나 시간이 불보다 작은 동안
        // 불이 더이상 번지지 않는 경우
        while (curJM < curFM || fq.empty()) {
            for (int i=0;i<4;i++) {
                int nextJR, nextJC;
                nextJR = curJR + dx[i]; nextJC = curJC + dy[i];
                if (nextJR >=0 && nextJR <R && nextJC >=0 && nextJC < C) {
                    if (arr[nextJR][nextJC] == can) {
                        arr[nextJR][nextJC] = J;
                        jq.push(Coordinate(nextJR, nextJC, curJM+1));
                    }
                }
            }

            if (!jq.empty()) { curJR = jq.front().r; curJC = jq.front().c; curJM = jq.front().m; jq.pop(); }
            else { curJR = -10; curJC = -10; break; }

            if (curJR == 0 || curJC == 0 || curJR == R-1 || curJC == C-1) return curJM+1;
        }
    }
    return -1;
}

int main() {
    string val;
    int answer;

    cin >> R >> C;
    for (int i=0;i<R;i++) {
        cin >> val;
        arr.push_back(val);
    }
    answer = bfs();
    if (answer == -1) cout << "IMPOSSIBLE" << endl;
    else cout << answer << endl;

    // 결과 확인용
    // for (int i=0;i<R;i++) {
    //     cout << arr[i] << endl;
    // }
}