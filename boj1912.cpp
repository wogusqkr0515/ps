#include <iostream>
#include <algorithm>

using namespace std;

int N;
int nums[100005];

void dp() {
    nums[0] = 0;
    for (int i=1;i<=N;i++) {
        nums[i] = max(nums[i], nums[i] + nums[i-1]);
    }

    cout << *max_element(nums+1, nums+N+1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=1;i<=N;i++) {
        cin >> nums[i];
    }

    dp();
}