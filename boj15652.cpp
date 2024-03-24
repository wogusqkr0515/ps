#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int nums[10];

void dfs(int n, int cnt) {
    if (cnt == M) {
        for (int i=0;i<M;i++) cout << nums[i] << " ";
        cout << '\n';
        return;
    }
    for (int i=n;i<=N;i++) {
        nums[cnt] = i;
        dfs(i, cnt+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    dfs(1,0);
}