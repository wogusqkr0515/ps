#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v;

int sol(int n) {
    int lo = 0;
    int hi = N-1;
    while (lo<=hi) {
        int mid = (lo+hi)/2;
        if (v[mid] > n) 
            hi = mid-1;
        else if (v[mid] < n) 
            lo = mid+1;
        else return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int val;
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> val;
        v.push_back(val);
    }
    sort(v.begin(), v.end());
    cin >> M;
    for (int i=0;i<M;i++) {
        cin >> val;
        // cout << sol(val) << '\n';
        cout << binary_search(v.begin(), v.end(), val) << '\n';
    }
}