#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[100000];

void sol() {
    int lo, hi, first, second, ans;
    lo = 0; hi = N-1; ans = 2e9+100;

    while (lo<hi) {
        int cur = arr[lo] + arr[hi];
        int num = abs(cur);

        if (ans>num) {
            ans = num;
            first = arr[lo]; second = arr[hi];
        }

        if (cur>0) hi--;
        else lo++;
    }

    cout << first << ' ' << second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=0;i<N;i++) 
        cin >> arr[i];
    
    sol();
}