#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N;
vector<int> v, vv;
map<int, int> m;

void sol() {
    int idx=0;
    int cnt = 0;
    while (idx < N) {
        m[v[idx]] = cnt;
        cnt++;
        idx = upper_bound(v.begin(), v.end(), v[idx]) - v.begin();
    }

    for (int i=0;i<N;i++) {
        cout << m[vv[i]] << " ";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int val;
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> val;
        v.push_back(val);
        vv.push_back(val);
    }
    sort(v.begin(), v.end());

    // sol();

    v.erase( unique(v.begin(), v.end()), v.end());
    for (int i=0;i<N;i++) {
        cout << lower_bound(v.begin(), v.end(), vv[i]) - v.begin() << " ";
    }
}