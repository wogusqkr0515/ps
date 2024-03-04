#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int L, C;
vector<char> arr;
char ans[15];
int visited[15] = {0,};
string mo = "aeiou";

void sol(int start, int depth) {
    if (depth == L) {
        int m, j;
        m =0; j = 0;
        string str = "";
        for (int i=0;i<L;i++) {
            str += ans[i];
            if (mo.find(ans[i]) == string::npos) j++;
            else m++;
        }
        if (m>=1 && j>=2) cout << str << '\n';
        return;
    }

    for (int i=start;i<C;i++) {
        if (!visited[i]) {
            visited[i] = 1;
            ans[depth] = arr[i];
            sol(i+1, depth+1);
            visited[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    char ch;
    cin >> L >> C;
    for (int i=0;i<C;i++) {
        cin >> ch;
        arr.push_back(ch);
    }
    sort(arr.begin(), arr.end());
    // for (int i=0;i<C;i++) cout << arr[i] << " ";
    sol(0, 0);
}