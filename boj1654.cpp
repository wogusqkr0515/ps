#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int K, N;
vector<int> klan;

bool sol(ll x) {
    ll cur = 0;
    for (int i=0;i<K;i++) cur += klan[i] / x;
    return cur >= N;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int val;
    cin >> K >> N;
    for (int i=0;i<K;i++) {
        cin >> val;
        klan.push_back(val);
    }
    sort(klan.begin(), klan.end());

    ll st, mid, ed;
    st = 1; ed = 0x7fffffff;
    while (st<ed) {
        mid = (st+ed+1)/2;
        if (sol(mid)) st = mid;
        else ed = mid-1;
    }
    cout << st;
}