#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int N;
vector<pair<int,int>> v;

bool cmp(pair<int,int> a, pair<int,int> b) {
    if (a.Y == b.Y) {
        return a.X < b.X;
    }
    return a.Y < b.Y;
}

void sol() {
    sort(v.begin(), v.end(), cmp);

    int cnt = 1;
    int cur = v[0].Y;
    
    for (int i=1;i<N;i++) {
        if (v[i].X < cur) continue;
        cur = v[i].Y;
        cnt++;
    }

    cout << cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=0;i<N;i++) {
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }

    sol();
}