#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int lcs[1001][1001];
string str1, str2;

void sol() {
    for (int i=1;i<=str1.length();i++) {
        for (int j=1;j<=str2.length();j++) {
            if (str1[i-1] == str2[j-1]) lcs[i][j] = lcs[i-1][j-1] + 1;
            else lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
        }
    }
    cout << lcs[str1.length()][str2.length()] << '\n';
    if (lcs[str1.length()][str2.length()] == 0) return;
    
    string ans = "";
    stack<char> st;
    int i = str1.length(), j=str2.length();
    while (i>0 && j>0) {
        if (lcs[i][j] == lcs[i-1][j]) i--;
        else if (lcs[i][j] == lcs[i][j-1]) j--;
        else {
            st.push(str1[i-1]);
            i--; j--;
        }  
    }

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str1;
    cin >> str2;

    sol();
}
