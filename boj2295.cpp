#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;

void sol() {
    vector<int> twosum;

    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            twosum.push_back(v[i]+ v[j]);
        }
    }
    sort(twosum.begin(), twosum.end());

    for (int i=N-1;i>=0;i--) {
        for (int j=0;j<N;j++) {
            if (binary_search(twosum.begin(), twosum.end(), v[i] - v[j])) { cout << v[i]; return; }
        }
    }
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

    sol();
}