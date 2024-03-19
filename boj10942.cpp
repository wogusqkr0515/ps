#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int nums[2005];
int answer[2005][2005];

void dp() {
    int start, end;

    for (int i=1;i<=N;i++) {
        answer[i][i] = 1;
        if (nums[i-1] == nums[i]) answer[i-1][i] = 1;
    }

    for (int gap = 2;gap<N;gap++) {
        for (int i = 1; i<=N-gap;i++) {
            start = i; end = i+gap;
            if (nums[start] == nums[end] && answer[start+1][end-1]) answer[start][end] = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int s,e;
    cin >> N;
    for (int i=1;i<=N;i++)
        cin >> nums[i];
    
    dp();
    
    cin >> M;
    for (int i=0;i<M;i++) {
        cin >> s >> e;
        cout << answer[s][e] << '\n';
    }
}