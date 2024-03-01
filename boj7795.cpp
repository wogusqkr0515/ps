#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int T, N, M, val;
    vector<vector<int>> A, B;

    cin >> T;
    for (int i=0;i<T;i++) {
        vector<int> iter;
        cin >> N >> M;
        for (int j=0;j<N;j++) {
            cin >> val;
            iter.push_back(val);
        }
        A.push_back(iter);
        iter.clear();
        for (int j=0;j<M;j++) {
            cin >> val;
            iter.push_back(val);
        }
        B.push_back(iter);
    }
    
    for (int i=0;i<T;i++) {
        int cnt = 0;
        int idx = 0;
        sort(A[i].begin(), A[i].end(), cmp);
        sort(B[i].begin(), B[i].end(), cmp);
        for (int j=0;j<A[i].size();j++) {
            for (int z=idx;z<B[i].size();z++) {
                if (A[i][j] > B[i][z]) {
                    cnt += B[i].size() - z;
                    break;
                }
                idx = z;
            }
        }
        cout << cnt << endl;
    }
}