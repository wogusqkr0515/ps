#include <iostream>
#include <algorithm>

using namespace std;

int T;
int x1,y,r1,x2,y2,r2;

void sol() {
    int d = (x1-x2)*(x1-x2) + (y-y2)*(y-y2);
    int cond1 = (r1-r2)*(r1-r2);
    int cond2 = (r1+r2)*(r1+r2);

    if (d==0 && cond1 == 0) cout << -1 << '\n';
    else if (d == cond1 || d == cond2) cout << 1 << '\n';
    else if (d>cond1 && d<cond2) cout << 2 << '\n';
    else cout << 0 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> x1 >> y >> r1 >> x2 >> y2 >> r2;

        sol();
    }
}