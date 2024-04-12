#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int unf[1000001];

int find(int x) {
    if (unf[x] == x) return x;
    return unf[x] = find(unf[x]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c;
    cin >> N >> M;
    for (int i=1;i<=N;i++) {
        unf[i] = i;
    }

    for (int i=0;i<M;i++) {
        cin >> c >> a >> b;
        a = find(a); b = find(b);
        if (c==0) 
            unf[a] = b;
        else {
            if (a == b) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}