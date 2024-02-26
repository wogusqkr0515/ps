#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n, val;
    vector<int> arr;

    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> val;
        arr.push_back(val);
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i=0;i<n;i++) {
        cout << arr[i] << '\n';
    }
}