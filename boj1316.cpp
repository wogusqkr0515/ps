#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int answer;

void check(string str) {
    set<char> chSet;
    char now;
    int sz;
    char prev = str[0];
    chSet.insert(prev);
    for (int i=1;i<str.length();i++) {
        now = str[i];
        if (prev != now) {
            prev = now;
            sz = chSet.size();
            chSet.insert(now);
            if (sz == chSet.size()) return;
        }
    }
    answer++;
}

int main() {
    vector<string> v;
    string inStr;
    int n;
    answer=0;

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> inStr;
        v.push_back(inStr);
    }
    for (int i=0;i<n;i++) {
        check(v[i]);
    }
    cout << answer << endl;
}