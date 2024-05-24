#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, L;
vector<int> v;

bool chk(int x) {
    int cnt=0, dist;
    
    for (int i=1;i<v.size();i++) {
        dist = v[i] - v[i-1];
        cnt += (dist / x);
        
        if (dist%x==0) cnt--;
    }

    return cnt <= M;
}

void sol() {
    sort(v.begin(), v.end());

    int lo,hi,mid;
    lo = 0; hi = 1001;

    while (lo+1<hi) {
        mid = (lo+hi) / 2;
        
        if (chk(mid)) hi = mid;
        else lo = mid;
    }

    cout << hi;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> N >> M >> L;
    for (int i=1;i<=N;i++) {
        cin >> n;
        v.push_back(n);
    }
    v.push_back(0);
    v.push_back(L);

    sol();
}