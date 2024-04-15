#include <iostream>
#include <algorithm>

using namespace std;

int N,M;
int nums[10];

void dfs(int num, int step) {
    if (step == M) {
        for (int i=0;i<step;i++) cout << nums[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i=1;i<=N;i++) {
        nums[step] = i;
        dfs(i, step+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    dfs(1,0);
}