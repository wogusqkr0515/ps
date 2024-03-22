#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int N, M;
vector<int> tree;

bool check(const int target) {
    ll sum = 0;
    for (int i=0;i<N;i++) {
        if (tree[i] > target)
            sum += (tree[i] - target);
    }
    return sum >= M;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int val;
    cin >> N >> M;
    for (int i=0;i<N;i++) {
        cin >> val;
        tree.push_back(val);
    }

    int st, ed, mid;
    st = 0; ed = 1000000000;

    while (st+1<ed) {
        mid = (st+ed)/2;
        if (check(mid)) st = mid;
        else ed = mid;
    }
    
    cout << st;
}