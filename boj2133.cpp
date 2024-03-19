#include <iostream>
#include <algorithm>

using namespace std;

int N;
int answer[35];

void dp() {
    if (N%2!=0) { cout << 0; return; }
    
    answer[0] = 1; answer[2] = 3; 
    for (int i=4;i<=N;i+=2) {
        answer[i] += answer[i-2] * 3;
        for (int j= i-4;j>=0;j-=2)
            answer[i] += answer[j] * 2;
    }
    cout << answer[N];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    dp();
}