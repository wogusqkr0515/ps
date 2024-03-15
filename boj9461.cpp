#include <iostream>
#include <algorithm>

using namespace std;

int T;
long long nums[110];

void dp() {
    nums[1] = 1; nums[2] = 1; nums[3] = 1;
    nums[4] = 2; nums[5] = 2; nums[6] = 3;
    nums[7] = 4; nums[8] = 5; nums[9] = 7;

    for (int i=10;i<101;i++) {
        nums[i] = nums[i-1] + nums[i-5];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    dp();

    cin >> T;
    for (int i=0;i<T;i++) {
        cin >> n;
        cout << nums[n] << '\n';
    }
}