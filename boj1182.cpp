#include <iostream>
using namespace std;

int N, S, cnt;
int nums[20] = {0,};

void dfs(int step, int sum) {
    if (step == N) {
        if (sum == S) cnt++;
        return ;
    }
    dfs(step+1, sum);
    dfs(step+1, sum+nums[step]);
}

int main() {
    int val;
    cnt = 0;
    cin >> N >> S;
    for (int i=0;i<N;i++) {
        cin >> val;
        nums[i] = val;
    }
    dfs(0, 0);
    if (S == 0) cnt--;
    cout << cnt << '\n';
}