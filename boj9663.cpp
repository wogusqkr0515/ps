#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, cnt;
bool isused1[15] = {false,};
bool isused2[30] = {false,};
bool isused3[30] = {false,};

void sol(int row) {
    if (row == N) {
        cnt++;
        return;
    }

    for (int i=0;i<N;i++) {
        if (isused1[i] || isused2[i+row] || isused3[i-row+N-1]) continue;

        isused1[i] = true;
        isused2[i+row] = true;
        isused3[i-row+N-1] = true;
        sol(row+1);
        isused1[i] = false;
        isused2[i+row] = false;
        isused3[i-row+N-1] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cnt = 0;
    cin >> N;
    sol(0);
    cout << cnt;
}