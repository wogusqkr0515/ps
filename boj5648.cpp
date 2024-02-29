#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long num;
    string val;
    vector<string> sArr;
    vector<long long> arr;

    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> val;
        sArr.push_back(val);
    }
    for (int i=0;i<n;i++) {
        num = 0;
        for (int j=1;j<=sArr[i].length();j++) {
            num *= 10;
            num += sArr[i][sArr[i].length() - j] - '0';
        }
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    for (int i=0;i<n;i++) {
        cout << arr[i] << '\n';
    }
}