#include <iostream>
#include <algorithm>

using namespace std;

int N;
int mod = 1000000009;
int nums[1000005];

void dp() {
    nums[1] = 1;
    nums[2] = 2;
    nums[3] = 4;
    for (int i=4;i<=1000000;i++) {
        nums[i] = ((nums[i-1] + nums[i-2]) % mod + nums[i-3]) % mod;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp();

    int n;
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> n;
        cout << nums[n] << '\n';
    }
}