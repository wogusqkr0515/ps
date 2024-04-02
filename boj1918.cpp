#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

string str, answer = "";
unordered_map<char, int> priority;

void sol() {
    stack<char> st;
    
    priority['+'] = 1; priority['-'] = 1;
    priority['*'] = 2; priority['/'] = 2;
    priority['('] = 3; priority[')'] = 4;
    
    for (int i=0;i<str.length();i++) {
        if (priority[str[i]] == 0) answer += str[i];
        else if (priority[str[i]] == 4) {
            while (st.top() != '(') {
                answer += st.top();
                st.pop();
            }
            st.pop();
        }
        else if (priority[str[i]] == 3) st.push(str[i]);
        else if (priority[str[i]] == 2) {
            if (!st.empty() && priority[st.top()] == 2 ) {
                answer += st.top();
                st.pop();
            } 
            st.push(str[i]);
        }
        else if (priority[str[i]] == 1) {
            while (!st.empty() && priority[st.top()] != 3) {
                answer += st.top();
                st.pop();
            } 
            st.push(str[i]);
        }
    }
    
    while (!st.empty()) {
        if (st.top() != '(') answer += st.top();
        st.pop();
    }

    cout << answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    sol();
}