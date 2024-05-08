#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, ans=-2e9-1e8-4e7;
string str;

int getNum(int idx) {
    return str[idx] - '0';
}

int calc(int idx, int a, int b) {
    if (str[idx] == '+') return a + b;
    else if (str[idx] == '-') return a - b;
    return a * b;
}

void dfs(int idx, int sum) {
    if (idx >= N) {
        ans = max(ans, sum);
        return;
    }
    int a,b;
    a = getNum(idx);
    b = calc(idx-1, sum, a);
    
    if (idx < N-2) {
        int c = getNum(idx+2);
        a = calc(idx+1, a, c);
        a = calc(idx-1, sum, a);
        dfs(idx+4, a);
    } 
    dfs(idx+2, b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cin >> str;

    dfs(2,getNum(0));
    cout << ans;
}