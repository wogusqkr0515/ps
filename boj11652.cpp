#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(long long a, long long b) {
    return a < b;
}

int main() {
    int N, cnt, maxCnt;
    long long val, ans;
    vector<long long> arr;

    cnt = 0; maxCnt = 0;
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> val;
        arr.push_back(val);
    }
    sort(arr.begin(), arr.end(), cmp);
    ans = arr[0];
    for (int i=0;i<N-1;i++) {
        if (arr[i] == arr[i+1]) cnt++;
        else cnt = 0;
        if (cnt > maxCnt) { ans = arr[i]; maxCnt = cnt; }
    }
    cout << ans << endl;
}