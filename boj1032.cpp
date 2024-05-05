#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, len;
vector<string> v;

void sol() {
    string answer = "";
    len = v[0].length();

    for (int i=0;i<len;i++) {
        answer += v[0][i];
        for (int j=1;j<N;j++) {
            if (answer[i] != v[j][i]) {
                answer[i] = '?';
                break;
            }
        }
    }

    cout << answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> str;
        v.push_back(str);
    }

    sol();
}