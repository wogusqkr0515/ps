#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
int nums[10];

void dfs(int num, int cnt) {
    
    if (cnt == m) {
        for (int i=0;i<m;i++) cout << nums[i] <<" ";
        cout << '\n';
        return;
    }

    for (int i=num;i<n;i++) {
        nums[cnt] = i+1;
        dfs(i+1, cnt+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v, vv;
    bool flag;
    cin >> n >> m;
    // dfs(0, 0);
    for (int i=1;i<=n;i++) v.push_back(i);

    do {
        flag = false;
        vv.clear();
        for (int i=0;i<m;i++) {
            vv.push_back(v[i]);
            if (i==0) continue;
            if (v[i-1] > v[i] ) { flag = true; break; }
        }
        if (flag) continue;
        for (int i=0;i<m;i++) cout << vv[i] << " ";
        cout << endl;
        reverse(v.begin()+m, v.end());
    } while(next_permutation(v.begin(), v.end()));
}