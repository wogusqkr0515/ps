#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;

ll mod = 1000000007;
map<ll, ll> m;

ll fibo(ll num) {
    if (num == 0) return 0;
    if (num == 1) return 1;
    if (num == 2) return 1;

    if (m[num] > 0) return m[num];

    ll a, b;
    ll numdiv = num/2;

    if (m[numdiv] > 0) a = m[numdiv];
    else a = fibo(numdiv);

    if (num % 2 ==0) {
        if (m[numdiv-1] > 0) b = m[numdiv-1];
        else b = fibo(numdiv-1);
        
        m[num] = (a*a + 2*a*b) % mod;
    } else {
        if (m[numdiv+1] > 0) b = m[numdiv+1];
        else b = fibo(numdiv+1);

        m[num] = (a*a + b*b) % mod;
    }

    return m[num];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;

    cout << fibo(N);
}