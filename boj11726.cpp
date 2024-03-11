#include <iostream>
#include <algorithm>

using namespace std;

int N;
int answer[1001];

void sol() {
    answer[1] = 1;
    answer[2] = 2;

    for (int i=3;i<=N;i++) {
        answer[i] = (answer[i-1] + answer[i-2]) % 10007;
    }
    cout << answer[N];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    sol();
}