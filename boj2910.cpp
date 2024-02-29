#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

struct Th {
    int num, cnt, idx;
    Th(int n, int c, int i): num(n), cnt(c), idx(i) {};
};

bool cmp(Th a, Th b) {
    if (a.cnt == b.cnt) return a.idx < b.idx;
    return a.cnt > b.cnt;
}

int main() {
    int N, C, val;
    vector<int> nums;
    vector<Th> arr;
    map<int, int> cnt;
    map<int, int> idx;

    cin >> N >> C;
    for (int i=0;i<N;i++) {
        cin >> val;
        nums.push_back(val);
        if (cnt[val] == 0)
            idx[val] = i;
        cnt[val]++;
        
    }
    for (int i=0;i<N;i++) {
        int n = nums[i];
        arr.push_back(Th(n, cnt[n], idx[n]));
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i=0;i<N;i++) {
        cout << arr[i].num << " ";
    }
}