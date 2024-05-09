#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int N, ans=-2e9-1e8-4e7;
string str;
unordered_map<char, int> um;

void calc(string s) {
    stack<char> op;
    stack<int> nums;
    int a,b,c;

    for (int i=0;i<s.length();i++) {
        if (um[s[i]] == 0) nums.push(s[i] - '0');
        else if (um[s[i]] == 4) {
            while (um[op.top()] != 3) {
                b = nums.top(); nums.pop();
                a = nums.top(); nums.pop();
                if (op.top() == '+') c = a+b;
                else if (op.top() == '-') c = a-b;
                else c = a*b;
                op.pop();
                nums.push(c);
            }
            op.pop();
        }
        else if (um[s[i]] == 3) op.push(s[i]);
        else if (um[s[i]] == 2) {
            while (!op.empty() && um[op.top()] == 2) {
                b = nums.top(); nums.pop();
                a = nums.top(); nums.pop();
                if (op.top() == '+') c = a+b;
                else if (op.top() == '-') c = a-b;
                else c = a*b;
                op.pop();
                nums.push(c);
            }
            op.push(s[i]);
        }
        else {
            while (!op.empty() && um[op.top()] != 3) {
                b = nums.top(); nums.pop();
                a = nums.top(); nums.pop();
                if (op.top() == '+') c = a+b;
                else if (op.top() == '-') c = a-b;
                else c = a*b;
                op.pop();
                nums.push(c);
            }
            op.push(s[i]);
        }
    }

    while (!op.empty()) {
        if (um[op.top()] != 3) {
            b = nums.top(); nums.pop();
            a = nums.top(); nums.pop();
            if (op.top() == '+') c = a+b;
            else if (op.top() == '-') c = a-b;
            else c = a*b;
            nums.push(c); 
        }
        op.pop();
    }
    
    ans = max(ans, nums.top());
}

void dfs(int idx, string s) {
    if (idx >= N-1) {
        if (idx == N-1) s+= str[idx];
        calc(s);
        return;
    }
    string tmp;
    if (um[str[idx+1]] == 1) {
        tmp = "";
        tmp += '(';
        for (int i=0;i<3;i++)
            tmp += str[idx+i];
        tmp += ')';
        if (idx < N-4) tmp += str[idx+3];
        dfs(idx+4, s+tmp);
    }

    tmp = "";
    for (int i=0;i<2;i++)
        tmp += str[idx+i];
    dfs(idx+2, s+tmp);
}

void sol() {
    um['('] = 3; um[')'] = 4;
    um['*'] = 2;
    um['+'] = 1; um['-'] = 1;

    dfs(0, "");
    
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cin >> str;

    sol();
}