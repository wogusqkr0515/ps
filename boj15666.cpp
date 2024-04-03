#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int nums[10];
vector<int> v;

void dfs(int idx, int cnt) {
    if (cnt == M) {
        for (int i=0;i<M;i++) 
            cout << nums[i] << " ";
        cout << '\n';
        return;
    }

    for (int i=idx;i<v.size();i++) {
        nums[cnt] = v[i];
        dfs(i, cnt+1);
    }
}

void sol() {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    dfs(0,0);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int val;
    cin >> N >> M;

    for (int i=0;i<N;i++) {
        cin >> val;
        v.push_back(val);
    }

    sol();
}