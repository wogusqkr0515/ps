#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int arr[51][10];

void sol() {
    int ans = 0;
    vector<int> v;
    for (int i=2;i<10;i++) {
        v.push_back(i);
    }

    do {
        int idx = 0, score = 0, num;
        for (int i=0;i<N;i++) {
            int out = 0;
            bool base[4] = {false,};
            while (out < 3) {
                if (idx==3) num = 1;
                else if (idx >3) num = v[idx-1];
                else num = v[idx];

                int move = arr[i][num];
                if (++idx == 9) idx = 0;
                if (!move) {
                    out++;
                    continue;
                }

                base[0] = true;
                for (int j=3;j>=0;j--) {
                    if (!base[j]) continue;
                    if (j+move >3) score++;
                    else base[j+move] = true;
                    base[j] = false;
                }
            }
        }
        ans = max(ans, score);
    } while (next_permutation(v.begin(), v.end()));

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=0;i<N;i++) {
        for (int j=1;j<10;j++) {
            cin >> arr[i][j];
        }
    }

    sol();
}