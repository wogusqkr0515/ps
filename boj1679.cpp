#include <iostream>
#include <queue>
using namespace std;

int N, K;

struct Pair {
    int n, s;
    Pair(int num, int step): n(num), s(step) {} ;
};

int bfs() {
    queue<Pair> q;
    int visited[100001] = {0};

    q.push(Pair(N, 0));
    visited[N] = 1;
    while (!q.empty()) {
        int curNum, curStep;
        curNum = q.front().n; curStep = q.front().s;
        q.pop();
        if (curNum == K) return curStep;
        if (curNum < K) {
            if (curNum+1 < 100001 && visited[curNum+1] == 0) {
                q.push(Pair(curNum+1, curStep+1));
                visited[curNum+1] = 1;
            }
            if (curNum*2 < 100001 && visited[curNum*2] == 0) {
                q.push(Pair(curNum*2, curStep+1));
                visited[curNum+1] = 1;
            }
        }
        if (curNum>0 && visited[curNum-1] == 0) {
            q.push(Pair(curNum-1, curStep+1));
            visited[curNum-1] = 1;
        }
    }
    return -1;
}

int main() {
    int answer;

    cin >> N >> K;
    answer = bfs();
    cout << answer << endl;
}