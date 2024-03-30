#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> st;
    int K, val,sum = 0;
    cin >> K;
    for (int i=0;i<K;i++){
        cin >> val;
        sum += val;
        if (val==0) { sum -= st.top(); st.pop(); }
        else st.push(val);
    }
    cout << sum;
}