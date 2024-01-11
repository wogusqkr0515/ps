#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N, num;
    stack<int> st;
    string Push, Pop, Size, Empty, Top, inp;
    vector<int> answer;
    Push = "push";
    Pop = "pop";
    Size = "size";
    Empty = "empty";
    Top = "top"; 

    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> inp;
        if (inp == Push) {
            cin >> num;
            st.push(num);
        }
        if (inp == Pop) {
            if (st.empty()) answer.push_back(-1); //cout << "-1" << endl;
            else {
                // cout << st.top() << endl;
                answer.push_back(st.top());
                st.pop();
            }
        }
        if (inp == Size) answer.push_back(st.size()); //cout << st.size() << endl;
        if (inp == Empty) {
            if (st.empty()) answer.push_back(1); //cout << "1" << endl;
            else answer.push_back(0); //cout << "0" << endl;
        }
        if (inp == Top) {
            if (st.empty()) answer.push_back(-1); //cout << "-1" << endl;
            else answer.push_back(st.top()); //cout << st.top() << endl;
        }
    }
    for (int iter : answer) cout << iter << endl;
}