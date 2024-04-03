#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int nums[10];
vector<int> arr;

void dfs(int idx, int cnt) {
    if (cnt == M) {
        for (int i=0;i<M;i++) cout << nums[i] << " ";
        cout << endl;   
        return;
    }

    for (int i=idx;i<N;i++) {
        nums[cnt] = arr[i];
        dfs(i, cnt+1);
    }
}

void sol() {
    sort(arr.begin(), arr.end());

    dfs(0,0);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int val;
    cin >> N >> M;

    for (int i=0;i<N;i++) {
        cin >> val;
        arr.push_back(val);
    }

    sol();
}