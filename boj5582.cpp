#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string str1, str2;
int len1, len2;
int com[4005][4005];
    
void lcs() {
    int answer = 0;
    len1 = str1.length(); len2 = str2.length();

    for (int i=0;i<len1+1;i++) {
        for (int j=0;j<len2+1;j++) {
            if (i==0 || j==0) com[i][j] = 0;
            else if (str1[i-1] == str2[j-1]) {
                com[i][j] = com[i-1][j-1] + 1;
                answer = max(answer, com[i][j]);
            }
            else {
                com[i][j] = 0;
            }
        }
    }

    cout << answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str1 >> str2;
    
    lcs();
}