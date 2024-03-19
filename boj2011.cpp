#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, len;
int secret[5005];
int answer[5005];

void dp() {
    answer[0] = 1;
    for (int i=1;i<=len;i++) {
        if (secret[i]>0) answer[i] = (answer[i]+ answer[i-1]) % 1000000;
        int x = secret[i-1] * 10 + secret[i];
        if (x>=10 && x <= 26) answer[i] = (answer[i]+ answer[i-2]) % 1000000;
    }

    cout << answer[len];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string n;
    cin >> n;
    
    len = n.length();
    for (int i=1;i<=len;i++) {
        secret[i] = n[i-1] - '0';
    }

    dp();
}