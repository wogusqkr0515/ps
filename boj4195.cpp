#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int T, M, cnt;
int unf[200001];
int fcnt[200000];
vector<pair<string, string>> v;

int find(int x) {
    cnt++;
    if (unf[x] == x) return x;
    return unf[x] = find(unf[x]);
}

void sol() {
    int a, b, idx=0;;
    unordered_map<string, int> m;

    for (int i=1;i<=M*2;i++) { unf[i] = i; fcnt[i] = 1; }

    for (int i=0;i<M;i++) {
        string str1, str2;
        str1 = v[i].X; str2 = v[i].Y;
        
        if (m[str1] == 0) m[str1] = ++idx;
        if (m[str2] == 0) m[str2] = ++idx;

        cnt = 0; a = find(m[str1]); fcnt[a] = max(fcnt[a], cnt);
        cnt = 0; b = find(m[str2]); fcnt[b] = max(fcnt[b], cnt);
        
        if (a != b) {
            unf[a] = b;
            fcnt[b] += fcnt[a];
        }

        cout << fcnt[b] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b;
    string str1, str2;
    cin >> T;
    for (int i=0;i<T;i++) {
        cin >> M;
        v.clear();
        for (int i=0;i<M;i++) {
            cin >> str1 >> str2;
            v.push_back({str1, str2});
        }

        sol();
    }
}