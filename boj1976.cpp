#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int unf[201];

int find(int x) {
    if (unf[x] == x) return x;
    return unf[x] = find(unf[x]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c;
    bool flag = true;
    cin >> N >>M;
    for (int i=1;i<=N;i++) unf[i] = i;

    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            cin >> c;
            if (c==1 && i<j) {
                a=find(i); b=find(j);
                unf[a] = b;
            }
        } 
    }

    if (M!=0) cin >> a;
    for (int i=1;i<M;i++) {
        cin >> b;
        if (find(a) != find(b)) flag = false;
        a = b;
    }

    if (flag) cout << "YES";
    else cout << "NO";
}