#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string br, hr;
vector<string> v;

void sol() {
    int cnt = 0;
    
    for (int i=0;i<v.size();i++) {
        if (v[i] == br) {
            cout << '\n';
            cnt = 0;
            continue;
        }
        if (v[i] == hr) {
            if (cnt != 0) cout << '\n';
            cout << "--------------------------------------------------------------------------------";
            cout << '\n';
            cnt = 0;
            continue;
        }
        if (cnt + v[i].length() < 80) {
            if (cnt != 0) {
                cout << " ";
                cnt++;
            }
            cout << v[i];
            cnt += v[i].length();
        }
        else {
            cout << '\n';
            cnt = 0;
            cout << v[i];
            cnt += v[i].length();
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string inp;
    
    br = "<br>";
    hr = "<hr>";
    while (true) {
        cin >> inp;
        // if (inp == "<<") break;
        if (cin.eof() == true) break;
        v.push_back(inp);
    }

    sol();
}