#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int unf[500001];

int find(int x) {
    if (unf[x] == x) return x;
    return unf[x] = find(unf[x]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    bool flag = false;
    int a,b,idx=1;
    cin >> N >> M;

    for (int i=0;i<N;i++) unf[i] = i;

    for (int i=1;i<=M;i++) {
        cin >> a >> b;

        if (flag) continue;
        a = find(a); b = find(b);
        if (a==b) { flag = true; continue; }  
        unf[a] = b;
        idx++;
    }

    if (flag) cout << idx;
    else cout << 0;
}