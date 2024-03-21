#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
vector<int> v;
int nums[10];
bool isvisit[10] = {false,};

void dfs(int cnt) {
    if (cnt == M) {
        for (int i=0;i<M;i++) cout << nums[i] <<" ";
        cout << '\n';
        return;
    }
    for (int i=0;i<N;i++) {
        if (isvisit[i]) continue;
        isvisit[i] = true;
        nums[cnt] = v[i];
        dfs(cnt+1);
        isvisit[i] = false;
    }
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
    sort(v.begin(), v.end());
    // dfs(0);
    do {
        for (int i=0;i<M;i++) cout << v[i] << " ";
        cout << "\n";
        reverse(v.begin() + M, v.end());
    } while(next_permutation(v.begin(), v.end()));
}