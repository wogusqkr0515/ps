#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string str;

void sol() {
    istringstream ss(str);
    string buffer;
    vector<string> v;
    int idx = -1;

    while (getline(ss, buffer, ':')) {
        if (buffer.length() == 0) {
            if (idx == -1) idx = v.size();
        }
        else if (buffer.length() < 4) {
            string s = "";
            for (int i=0;i<4 - buffer.length();i++) s += '0';
            for (int i=0;i<buffer.length();i++) s += buffer[i];
            v.push_back(s);
        } else {
            v.push_back(buffer);
        }
    }

    for (int i=0;i<v.size();i++) {
        if (i==idx) {
            for (int j=0;j<8-v.size();j++)
                cout << "0000:";
        }
        cout << v[i];
        if (i!=v.size()-1) cout << ":";
    }
    if (idx == v.size()) {
        for (int i=0;i<8-v.size();i++) {
            if (i==0 && idx!=0) cout << ":";
            cout << "0000";
            if (i != 7-v.size()) cout << ":";
        }
    } 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    sol();
}