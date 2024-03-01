#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int len;
    string val, str;
    vector<string> arr;

    cin >> val;
    len = val.length();
    str = "";
    for (int i=0;i<len;i++) {
        str = val.substr(i, len-i);
        arr.push_back(str);
    }
    sort(arr.begin(), arr.end());
    for (int i=0;i<len;i++) cout << arr[i] << '\n';
}