#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N, M, cnt;
vector<int> v;

int higher(int n) {
    int lo, hi, mid;
    lo = 0; hi = N;
    while (lo<hi) {
        mid = (lo+hi)/2;
        if (v[mid] > n) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int lower(int n) {
    int lo, hi, mid;
    lo = 0; hi = N;
    while (lo<hi) {
        mid = (lo+hi)/2;
        if (v[mid] >= n) hi = mid;
        else lo = mid + 1;
    }
    return lo;
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
        // cout << higher(val) - lower(val) << " ";
        cout << upper_bound(v.begin(), v.end(), val) - lower_bound(v.begin(), v.end(), val) << " ";
    }
}