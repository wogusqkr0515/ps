#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, MIN = -2e9-4e8-1e7, MAX = 2e9;
int dpMax[20][20], dpMin[20][20];
string str;

int getNum(int idx) {
    return str[idx] - '0';
}

int calc(int idx, int a, int b) {
    if (str[idx] == '+') return a+b;
    else if (str[idx] == '-') return a-b;
    return a*b;
}

void sol() {
    for (int i=0;i<N;i+=2) {
        for (int j=i;j<N;j+=2) {
            if (i==j) {
                dpMax[i][i] = getNum(i);
                dpMin[i][i] = dpMax[i][i];
            }
            else {
                dpMax[i][j] = calc(j-1, dpMax[i][j-2], getNum(j));
                dpMin[i][j] = dpMax[i][j];
            }
        }
    }

    for (int len = 2;len<N;len+=2) {
        for (int j=0;j+len<N;j+=2) {
            dpMax[j][j+len] = MIN;
            dpMin[j][j+len] = MAX;
            for (int k=j;k<j+len;k+=2) {
                dpMax[j][j+len] = max(dpMax[j][j+len], calc(k+1, dpMax[j][k], dpMax[k+2][j+len]));
                dpMax[j][j+len] = max(dpMax[j][j+len], calc(k+1, dpMax[j][k], dpMin[k+2][j+len]));
                dpMax[j][j+len] = max(dpMax[j][j+len], calc(k+1, dpMin[j][k], dpMax[k+2][j+len]));
                dpMax[j][j+len] = max(dpMax[j][j+len], calc(k+1, dpMin[j][k], dpMin[k+2][j+len]));

                dpMin[j][j+len] = min(dpMin[j][j+len], calc(k+1, dpMax[j][k], dpMax[k+2][j+len]));
                dpMin[j][j+len] = min(dpMin[j][j+len], calc(k+1, dpMax[j][k], dpMin[k+2][j+len]));
                dpMin[j][j+len] = min(dpMin[j][j+len], calc(k+1, dpMin[j][k], dpMax[k+2][j+len]));
                dpMin[j][j+len] = min(dpMin[j][j+len], calc(k+1, dpMin[j][k], dpMin[k+2][j+len]));
            }
        }
    }

    cout << dpMax[0][N-1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cin >> str;

    sol();
}