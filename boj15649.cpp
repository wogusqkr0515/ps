#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int nums[9] = {0,};
int visited[9] = {0,};

void dfs(int step) {
    if (step == M) {
        for (int i=0;i<M;i++) cout << nums[i] << " ";
        cout << '\n';
        return; 
    }
    for (int i=1;i<=N;i++) {
        if (visited[i] == 0) {
            nums[step] = i;
            visited[i] = 1;
            dfs(step+1);
            visited[i] = 0;
        }
    }
}

int main() {
    
    cin >> N >> M;

    dfs(0);
}