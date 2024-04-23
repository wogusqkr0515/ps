#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int N, K;
vector<pair<int,pair<int,int>>> MV;
vector<int> C;

void sol() {
    sort(MV.begin(), MV.end());
    sort(C.begin(), C.end());

    int idx=0;
    long long ans = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> pq;
    
    for (int i=0;i<K;i++) {
        while (idx<N && C[i]>=MV[idx].X) {
            pq.push(MV[idx++].Y);
        }

        if (!pq.empty()) {
            ans += pq.top().X;
            pq.pop();
        }
    }
    
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b;
    cin >> N >> K;
    for (int i=0;i<N;i++) {
        cin >> a >> b;
        MV.push_back({a,{b,a}});
    }
    for (int i=0;i<K;i++) {
        cin >> a;
        C.push_back(a);
    }

    sol();
}