#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int N;
int arr[100000];

void twopointer() {
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

void binary() {
    int lo, mid, hi, first, second, ans = 2e9+100;
    
    for (int i=0;i<N-1;i++) {
        int flag = arr[i];
        lo =i; hi = N;

        while (lo+1<hi) {
            mid = (lo+hi)/2;
            int cur = flag + arr[mid];

            if (ans > abs(cur)) {
                ans = abs(cur);
                first = flag;
                second = arr[mid];
            }

            if (cur>0) hi = mid;
            else lo = mid;
        }
    }

    cout << first << ' ' << second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=0;i<N;i++) 
        cin >> arr[i];
    
    // twopointer();
    binary();
}