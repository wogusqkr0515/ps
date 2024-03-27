#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int a,b,c;

ll pow(int rep) {
    if (rep==0) return 1;
    if (rep==1) return a%c;
    ll k = pow(rep/2) % c;
    if (rep%2==0) return k * k % c;
    return k*k%c *a % c;
}

void sol() {
    cout << pow(b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;

   sol();
}