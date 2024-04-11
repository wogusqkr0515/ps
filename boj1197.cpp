#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V,E;
int unf[10001];
tuple<int, int, int> edges[100001];

int find(int x) {
    if (unf[x] == x) return x;
    return unf[x] = find(unf[x]);
}

bool isDiff(int a, int b) {
    int v1, v2;
    v1 = find(a); v2 = find(b);

    if (v1==v2) return false;

    unf[v1] = v2;
    return true;
}

void sol() {
    int ans=0, cnt=0, idx=0;
    sort(edges, edges+E);

    for (int i=1;i<=V;i++) unf[i] = i;

    while (cnt<V-1) {
        int a,b,c;
        tie(c,a,b) = edges[idx++];
        if (!isDiff(a,b)) continue;

        ans += c;
        cnt++;
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E;
    for (int i =0;i<E;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        edges[i] = {c,a,b};
    }

    sol();
}