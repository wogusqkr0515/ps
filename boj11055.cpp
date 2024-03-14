#include <iostream>
#include <algorithm>

using namespace std;

int N;
int nums[1000];
int answer[1001];

void dp() {
    for (int i=0;i<N;i++) {
        for (int j=0;j<i;j++) {
            if (nums[j]<nums[i]) answer[i] = max(answer[i], answer[j] + nums[i]);
        }    
    }

    cout << *max_element(answer, answer + N);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> nums[i];
        answer[i] = nums[i];
    }

    dp();
}