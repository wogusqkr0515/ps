#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    if (a.length() != b.length()) return a.length() < b.length();

    return a < b;
}

int main() {
    int n;
    string s;
    vector<string> arr;

    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> s;
        arr.push_back(s);
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i=0;i<n;i++) {
        if (i>0 && arr[i] == arr[i-1]) continue;
        cout << arr[i] << endl;
    }
}