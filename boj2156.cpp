#include <iostream>
#include <algorithm>

using namespace std;

int N;
int wine[10000];
int answer[10000][3];

void dp() {
    answer[0][1] = wine[0]; 
    answer[1][0] = wine[0];
    answer[1][1] = wine[1];
    answer[1][2] = answer[0][1] + wine[1];
    int ans = answer[1][2];

    for (int i=2;i<N;i++) {
        answer[i][0] = ans;
        answer[i][1] = answer[i-1][0] + wine[i];
        answer[i][2] = answer[i-1][1] + wine[i];
        ans = max(answer[i][0], max(answer[i][1], answer[i][2])); 
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=0;i<N;i++) 
        cin >> wine[i];

    dp();
}