#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, people[11], ans = 10000;
vector<int> adj[11];
vector<int> a,b;
bool isa[11];

bool connectable(int st, int size, bool flag) {
    queue<int> q;
    bool chk[11] = {false,};
    int cnt = 0;
    q.push(st);
    chk[st] = true;

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        cnt++;

        for (int nxt : adj[cur]) {
            if (chk[nxt]) continue;
            if (isa[nxt] ^ flag) continue;

            chk[nxt] = true;
            q.push(nxt);
        }
    }

    if (cnt == size) return true;
    else return false;
}

bool chkConnect() {
    int st = a[0];
    if (!connectable(st, a.size(), true)) return false;

    st = b[0];
    if (!connectable(st, b.size(), false)) return false;

    return true;
}

void sol() {
    vector<int> v;
    for (int j=1;j<=N;j++)
        v.push_back(j);

    for (int i=1;i<=N/2;i++) {
        sort(v.begin(), v.end());

        do {
            int suma=0,sumb=0;
            a.clear(); b.clear();
            for (int j=1;j<=N;j++) isa[j] = false;

            for (int j=0;j<N;j++) {
                if (j<i) {
                    isa[v[j]] = true;
                    suma += people[v[j]];
                    a.push_back(v[j]);
                }
                else {
                    sumb += people[v[j]];
                    b.push_back(v[j]);
                }
            }
            
            if (chkConnect()) {
                ans = min(ans, max(suma, sumb) - min(suma, sumb));
            }

            reverse(v.begin() + i, v.end());
        } while(next_permutation(v.begin(), v.end()));
    }

    if (ans == 10000) cout << -1;
    else cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=1;i<=N;i++) {
        cin >> people[i];
    }
    int n;
    for (int i=1;i<=N;i++) {
        cin >> n;
        for (int j=0;j<n;j++) {
            int num;
            cin >> num;
            adj[i].push_back(num);
        }
    }

    sol();
}