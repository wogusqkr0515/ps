#include <iostream>
#include <algorithm>

using namespace std;

int N;
int nums[1000001][2];

void dp() {
    nums[1][0] = 0; nums[1][1] = 0;

    for (int i=2;i<=N;i++) {
        nums[i][0] = nums[i-1][0] + 1;
        nums[i][1] = i-1;
        if (i%2==0) {
            if (nums[i][0]>=nums[i/2][0]+1) {
                nums[i][0] = nums[i/2][0] + 1;
                nums[i][1] = i/2;
            }
        }
        if (i%3==0) {
            if (nums[i][0]>=nums[i/3][0]+1) {
                nums[i][0] = nums[i/3][0] + 1;
                nums[i][1] = i/3;
            }
        }
    }

    cout << nums[N][0] << '\n';
    int n = N;
    while (n > 0) {
        cout << n << " ";
        n =  nums[n][1];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    dp();
}