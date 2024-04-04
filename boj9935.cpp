#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

string str, bomb;
bool isBomb[1000000];

void sol() {
    stack<int> st;
    bool flag;
    fill(isBomb, isBomb+str.length(), false);

    for (int i=0;i<str.length();i++) {
        st.push(i);
        if (str[i] == bomb[bomb.length()-1]) {
            stack<int> iter;
            flag = false;
            
            for (int j=1;j<=bomb.length();j++) {
                if (!st.empty() && bomb[bomb.length()-j] == str[st.top()]) {
                    isBomb[st.top()] = true;
                    iter.push(st.top());
                    st.pop();
                    if (j == bomb.length()) flag = true;
                } else break;
            }

            if (!flag) {
                while (!iter.empty()) {
                    st.push(iter.top());
                    isBomb[iter.top()] = false;
                    iter.pop();
                }
            }
        }
    }
    
    flag = false;
    for (int i=0;i<str.length();i++) {
        if (isBomb[i]) continue;
        flag = true;
        cout << str[i];
    }
    if (!flag) cout << "FRULA"; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;
    cin >> bomb;

    sol();
}