#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<tuple<int,int,int>> edges;
int N, unf[1001];

int find(int x) {
    if (x==unf[x]) return x;
    return unf[x] = find(unf[x]);
}

bool is_diff(int a, int b) {
    a = find(a);
    b = find(b);

    if (a==b) return false;

    unf[a] = b;
    return true;
}

void sol() {
    sort(edges.begin(), edges.end());

    ll sum = 0;
    int cnt = 0;

    for (int i=1;i<=N;i++) unf[i] = i;
    for (int i=0;i<edges.size();i++) {
        int a,b,c;

        tie(c,a,b) = edges[i];
        if (!is_diff(a,b)) continue;

        sum += c;
        if(++cnt == N-1) break;
    }

    cout << sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c;
    cin >> N;
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            cin >> c;
            if (i>=j) continue;
            edges.push_back({c,i,j});
        } 
    }

    sol();
}