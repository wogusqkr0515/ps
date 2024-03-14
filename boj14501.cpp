#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


int N;
int answer[20];
int pay[20];
int day[20];

void dp() {
    for (int i=N;i>0;i--) {
        if (i+day[i] <= N+1) {
            answer[i] = max(answer[i+1], answer[i+day[i]] + pay[i]);
        }
        else answer[i] = answer[i+1];
    }

    cout << *max_element(answer, answer+N+1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(answer, 0, sizeof(answer));

    cin >> N;
    for (int i=1;i<=N;i++) {
        cin >> day[i] >> pay[i];
    }
    
    dp();
}