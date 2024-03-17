#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str1, str2;
int answer[1001][1001];

void dp() {
    int ans = 0;

    for (int i=0;i<str1.length()+1;i++) {
        for (int j=0;j<str2.length()+1;j++) {
            if (i==0 || j==0) {
                answer[i][j] = 0;
                continue;
            }
            if (str1[i-1] == str2[j-1]) {
                answer[i][j] = answer[i-1][j-1] + 1;
                ans = max(ans, answer[i][j]);
                continue;
            }
            answer[i][j] = max(answer[i-1][j], answer[i][j-1]);
            ans = max(ans, answer[i][j]);
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str1 >> str2;

    dp();
}