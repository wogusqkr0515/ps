#include <iostream>
#include <algorithm>

using namespace std;

int N;
int pay[1500060];
int day[1500060];
int answer[1500060];

void dp() {
    for (int i=N;i>0;i--) {
        if (i+day[i] <= N+1) {
            answer[i] = max(answer[i], answer[i+day[i]] + pay[i]);
        }
        answer[i-1] = answer[i];
    }

    cout << *max_element(answer, answer+N+1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=1;i<=N;i++)
        cin >> day[i] >> pay[i];

    dp();
}