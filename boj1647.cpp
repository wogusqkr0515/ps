#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int N, M;
int unf[100001];
vector<pair<int, pair<int,int>>> edges;

int find(int x) {
    if (x == unf[x]) return x;
    return unf[x] = find(unf[x]);
}

bool isSame(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return true;

    unf[a] = b;
    return false;
}

void sol() {
    if (N==2) {
        cout << 0;
        return;
    }

    vector<int> answer;
    sort(edges.begin(), edges.end());
    for (int i=1;i<=N;i++) unf[i] = i;

    for (int i=0;i<M;i++) {
        if (!isSame(edges[i].Y.X, edges[i].Y.Y)) {
            answer.push_back(edges[i].X);
        }

        if (answer.size() == N-2) break;
    }

    int ans = 0;
    for (int i=0;i<answer.size();i++) ans += answer[i];

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i=0;i<M;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        edges.push_back({c,{a,b}});
    }

    sol();
}