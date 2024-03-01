#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int ans[9] = {0,};
int nums[9] = {0,};
int visited[9] = {0,};
set<vector<int>> s;

void dfs(int step) {
    if (step == M) {
        vector<int> v;
        for (int i=0;i<M;i++) v.push_back(ans[i]);
        s.insert(v);
        return;
    }

    for (int i=0;i<N;i++) {
        if (!visited[i]) {
            ans[step] = nums[i];
            visited[i] = 1;
            dfs(step+1);
            visited[i] = 0;
        }
    }
}

int main() {
    int val;
    
    cin >> N >> M;
    for (int i=0;i<N;i++) {
        cin >> val;
        nums[i] = val;
    }
    sort(nums, nums + N);
    
    dfs(0);
    
    for (auto iter : s) {
        for (int i =0;i<iter.size();i++) {
            cout << iter[i] << " ";
        }
        cout << '\n';
    }
}