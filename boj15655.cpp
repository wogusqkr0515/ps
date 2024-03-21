#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v, vv;
int nums[10];

void dfs(int idx, int cnt) {
    if (cnt == M) {
        for (int i=0;i<M;i++) cout << nums[i] << " ";
        cout << '\n';
        return;
    }
    for (int i=idx;i<N;i++) {
        nums[cnt] = v[i];
        dfs(i+1,cnt+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int val;
    bool flag;
    cin >> N >> M;
    for (int i=0;i<N;i++) {
        cin >> val;
        v.push_back(val);
    }
    sort(v.begin(), v.end());
    // dfs(0,0);
    do {
        flag = false;
        vv.clear();
        for (int i=0;i<M;i++) {
            vv.push_back(v[i]);
            if (i==0) continue;
            if (v[i-1] > v[i]) {flag = true; break;}
        }
        reverse(v.begin() + M, v.end());
        if (flag) continue;
        for (int i=0;i<M;i++) cout << vv[i] << " ";
        cout << '\n';
    } while (next_permutation(v.begin(), v.end()));
}