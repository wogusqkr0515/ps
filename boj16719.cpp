#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

string str;
pair<char, bool> arr[100];

void printWord() {
    for (int i=0;i<str.length();i++) {
        if (arr[i].second) cout << arr[i].first;
    }
    cout << '\n';
}

void sol(int start, int end) {
    int minIdx = start;

    for (int i=start;i<=end;i++) {
        if (str[i] < str[minIdx]) minIdx = i;
    }

    arr[minIdx].second = true;
    printWord();

    if (minIdx+1 <= end) sol(minIdx+1, end);
    if (minIdx-1 >= start) sol(start, minIdx-1); 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;
    for (int i=0;i<str.length();i++) 
        arr[i] = make_pair(str[i], false);

    sol(0, str.length()-1);
}