#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

struct Pair {
    int n, d;
    Pair(int num, int depth): n(num), d(depth) {};
};

int N;

void bfs() {
    int cnt;
    map<int, int> isvisit;
    queue<Pair> q;
    q.push(Pair(N, 0));
    isvisit[N] = 1;

    while (!q.empty()) {
        int n = q.front().n; 
        cnt = q.front().d; q.pop();
        if (n==1) cout << cnt;
        if (n / 3 > 0 && n%3==0 && isvisit[n/3] == 0) {
            q.push(Pair(n/3, cnt+1));
            isvisit[n/3] = 1;
        }
        if (n / 2 > 0 && n%2==0 && isvisit[n/2] == 0) {
            q.push(Pair(n/2, cnt+1));
            isvisit[n/2] = 1;
        }
        if (n-1>0 && isvisit[n-1] == 0) {
            q.push(Pair(n-1, cnt+1));
            isvisit[n-1] = 1;
        }
    }
}

void dp() {
    int arr[1000001];

    arr[1] = 0;
    for (int i=2;i<=N;i++) {
        arr[i] = arr[i-1] + 1;
        if (i%2 == 0) arr[i] = min(arr[i], arr[i/2]+1);
        if (i%3 == 0) arr[i] = min(arr[i], arr[i/3]+1);
    }

    cout << arr[N];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    // bfs();
    dp();
}