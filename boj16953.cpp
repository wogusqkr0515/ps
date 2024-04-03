#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

#define X first
#define Y second
typedef long long ll;

int A, B;

void sol() {
    queue<pair<ll, int>> q;
    q.push({A, 1});

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        if (cur.X == B) {
            cout << cur.Y;
            return;
        }
        
        if (cur.X*2 <= B)
            q.push({cur.X*2, cur.Y+1});
        if (cur.X*10+1 <= B)
            q.push({cur.X*10+1, cur.Y+1});
    }
    cout << -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B;

    sol();
}