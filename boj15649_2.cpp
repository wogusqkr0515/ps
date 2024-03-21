#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    vector<int> v(N, 1);
    for (int i=0;i<N;i++) v[i] = i+1;

    do {
        for (int i=0;i<M;i++) 
            cout << v[i] << ' ';
        cout << '\n';
        reverse(v.begin()+M, v.end());
    } while(next_permutation(v.begin(), v.end()));
}