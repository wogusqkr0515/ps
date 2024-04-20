#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int N, mod = 1000000000;
unordered_map<int, int> m;

int fibo(int x) {
    if (x==0) return 0;
    if (x==1) return 1;

    if (m[x] > 0) return m[x];

    if (m[x-1] == 0) m[x-1] = fibo(x-1) % mod;
    if (m[x-2] == 0) m[x-2] = fibo(x-2) % mod;

    return m[x] = (m[x-1] + m[x-2]) % mod;
}

void sol() {
    if (N==0) return;
    bool flag = false;

    if (N<0) {
        N *= -1;
        flag = true;
    }

    m[1] = 1;
    fibo(N);
    
    if (flag && N%2==0) cout << "-1\n" << m[N];
    else cout << "1\n" << m[N];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    if (N==0) cout << N << '\n' << N;

    sol();
}