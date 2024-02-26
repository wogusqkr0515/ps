#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, val;
    vector<int> arr;

    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> val;
        arr.push_back(val);
    }
    sort(arr.begin(), arr.end());
    for (int i=0;i<n;i++) {
        cout << arr[i] << endl;
    }
}