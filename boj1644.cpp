#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
int isprime[4000001];

void sol() {
    if (N==1) { cout << 0; return; }
    vector<int> v;

    int idx = 0, sqt = sqrt(N);
    int tmp = 0, ans=0;

    for (int i=2;i<sqt+1;i++) {
        if (!isprime[i]) {
            for (int k=i*i;k<=N;k+=i) isprime[k] = true;
        }
    }

    for (int i=2;i<=N;i++) 
        if (!isprime[i]) v.push_back(i);

    for (int i=0;i<v.size();i++) {
        tmp += v[i];
        if (tmp >= N) {
            while (tmp > N && idx<i) tmp -= v[idx++];

            if (tmp == N) ans++;
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    sol();
}