#include <iostream>
#include <algorithm>

using namespace std;

int N;
int nums[1000];
int board[1000];
int board2[1000];

void sol() {
    int ans = 0;
    fill(board, board + N, 1);
    fill(board2, board2 + N, 1);

    for (int i=0;i<N;i++) 
        for (int j=i+1;j<N;j++) 
            if (nums[i] < nums[j]) board[j] = max(board[j], board[i] + 1);
    
    for (int i=N-1;i>=0;i--) 
        for (int j=i-1;j>=0;j--) 
            if (nums[i] < nums[j]) board2[j] = max(board2[j], board2[i] + 1);

    for (int i=0;i<N;i++) 
        ans = max(ans, board[i] + board2[i] - 1);

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=0;i<N;i++) 
        cin >> nums[i];

    sol();
}