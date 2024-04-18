#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int N, M;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int board[10][10];
pair<int, int> red, blue;

void bfs() {
    int idx;
    queue< pair< pair<int,int>, int > > bq, rq;
    bq.push({blue, 0 }); rq.push({red, 0 });

    while (true) {
        blue = bq.front().X; bq.pop();
        red = rq.front().X; idx = rq.front().Y; rq.pop();
        if (++idx == 11) break;
        
        for (int i=0;i<4;i++) {
            bool invalid = false;
            int bnr,bnc,bcnt, rnr,rnc,rcnt;

            bnr = blue.X + dy[i]; bnc = blue.Y + dx[i]; bcnt=1;
            while (true) {
                if (board[bnr][bnc] == -1) {
                    invalid = true;
                    break;
                }
                if (board[bnr][bnc] == 1) break;
                bnr += dy[i]; bnc += dx[i]; 
                bcnt++;
            }
            bnr += dy[(i+2)%4]; bnc += dx[(i+2)%4];

            if (invalid) continue;

            rnr = red.X + dy[i]; rnc = red.Y + dx[i]; rcnt=1;
            while (true) {
                if (board[rnr][rnc] == -1) {
                    cout << idx;
                    return;
                }
                if (board[rnr][rnc] == 1) break;
                rnr += dy[i]; rnc += dx[i];
                rcnt++;
            }
            rnr += dy[(i+2)%4]; rnc += dx[(i+2)%4];

            if (bnr == rnr && bnc == rnc) {
                if (bcnt>rcnt) { 
                    bnr += dy[(i+2)%4]; bnc += dx[(i+2)%4];
                }
                else { rnr += dy[(i+2)%4]; rnc += dx[(i+2)%4]; }
            }
            bq.push({{bnr, bnc}, idx}); rq.push({{rnr, rnc}, idx});
        }
    }

    cout << -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> N >> M;
    for (int i=0;i<N;i++) {
        cin >> str;
        for (int j=0;j<M;j++) {
            board[i][j] = 0;
            if (str[j] == '#') board[i][j] = 1;
            else if (str[j] == 'O') board[i][j] = -1;
            else if (str[j] == 'B') blue = {i,j};
            else if (str[j] == 'R') red = {i,j};
        }
    }

    bfs();
}