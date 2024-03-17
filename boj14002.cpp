#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int N;
int nums[1005];
pair<int, int> answer[1005];

void dp() {
    stack<int> st;
    int ans , idx;
    ans = 0;
    for (int i=0;i<N;i++) {
        for (int j=0;j<i;j++) {
            if (nums[j] < nums[i]) {
                if (answer[i].first < answer[j].first + 1) {
                    answer[i].first =  answer[j].first + 1;
                    answer[i].second = j;
                }
            }
        }
    }
    for (int i=0;i<N;i++) {
        if (ans < answer[i].first) {
            ans = answer[i].first;
            idx = i;
        }
    }

    cout << ans << '\n';
    while (idx >= 0) {
        st.push(idx);
        if (idx>=0) idx = answer[idx].second;
    }

    while (!st.empty()) {
        cout << nums[st.top()] << " ";
        st.pop();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> nums[i];
        answer[i] = make_pair(1, -1);
    }

    dp();
}