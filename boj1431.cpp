#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Pair {
    int idx;
    string str;
    Pair(int i, string s): idx(i), str(s) {};
};

bool cmp(string a, string b) {
    if (a.length() != b.length()) return a.length() < b.length();
    int asum, bsum;
    asum = 0; bsum = 0;
    for (int i=0;i<a.length();i++) {
        if (isdigit(a[i])) asum += a[i] - '0';
        if (isdigit(b[i])) bsum += b[i] - '0';
    }
    if (asum == bsum) return a < b;
    return asum < bsum;
}

int main() {
    int n;
    string str;
    vector<string> arr;

    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> str;
        arr.push_back(str);
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i=0;i<n;i++) {
        cout << arr[i] << '\n';
    }
}