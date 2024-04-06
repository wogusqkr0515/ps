#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;

int N;
ll M;
unordered_map<ll, vector<vector<int>> > m;

vector<vector<int>> getVec(vector<vector<int>> a, vector<vector<int>> b) {
    vector<int> v;
    vector<vector<int>> vv;

    for (int i=0;i<N;i++) v.push_back(0);
    for (int i=0;i<N;i++) vv.push_back(v);

    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            int s = 0;
            for (int k=0;k<N;k++) {
                s += (a[i][k] * b[k][j] % 1000);
            }
            vv[i][j] = s % 1000;
        }
    }

    return vv;
}

vector<vector<int>> mul(ll n) {
    if (n == 1) return m[1];

    ll div = n/2;
    vector<vector<int>> divVec, retVec;
    
    if (m.count(div) == 0) divVec = mul(div);
    else divVec = m[div];
    
    if (m.count(n) == 0) {
        retVec = getVec(divVec, divVec);
        if (n%2==1) retVec = getVec(retVec, m[1]);
        
        m[n] = retVec;
    } else retVec = m[n];

    return retVec;
}   

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int val;
    vector<int> initer;
    vector<vector<int>> iter;
    cin >> N >> M;
    for (int i=0;i<N;i++) {
        initer.clear();
        for (int j=0;j<N;j++) {
            cin >> val;
            initer.push_back(val);
        }
        iter.push_back(initer);
    }
    m[1] = iter;

    iter = mul(M);

    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            cout << iter[i][j]%1000 << " ";
        }
        cout << '\n';
    }
}