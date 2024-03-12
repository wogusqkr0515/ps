#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Pair {
    int i, t;
    Pair(int idx, int inTime): i(idx), t(inTime) {};
};

int N, W, L;
int truck[1000];

void sol() {
    int ans, idx, weight;
    queue<Pair> q;
    q.push(Pair(0,1));
    ans = 2; idx = 1; weight = truck[0];

    while (true) {
        while (true) {
            if (q.size() == W || idx == N) break;
            if (weight + truck[idx] > L) break;
            q.push(Pair(idx, ans));
            weight += truck[idx++];
            ans++;
        }

        while (true) {
            int outTruck = q.front().i;
            int time = q.front().t; q.pop();
            ans = max(time + W, ans);
            weight -= truck[outTruck];
            if (L >= weight) break;
        }

        if (idx == N ) {
            if (!q.empty()) {
                while (!q.empty()) {
                    idx = q.front().i;
                    ans = q.front().t;
                    q.pop();
                }
                ans += W;
                cout << ans;
                return; 
            }
            cout << ans;
            return;
        }
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> W >> L;
    for (int i=0;i<N;i++) {
        cin >> truck[i];
    }

    sol();
}