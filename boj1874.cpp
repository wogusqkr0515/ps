#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int nums[100001];

void sol() {
    stack<int> st;
    vector<char> v;
    int idx = 0;

    for (int i=1;i<=N;i++) {
        st.push(i);
        v.push_back('+');
        while (nums[idx] == st.top()) {
            st.pop();
            v.push_back('-');
            idx++;
            if (st.empty()) break;
        }
    }
    if (st.empty()) {
        for (auto iter : v) cout << iter << '\n';
    }
    else cout << "NO";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> nums[i];
    }

    sol();
}