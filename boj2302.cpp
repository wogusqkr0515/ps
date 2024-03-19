#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int seats[45];
vector<int> vip;

void dp() {
    int ans = 1;
    seats[0] = 1; seats[1] = 1;

    for (int i=2;i<=N;i++) 
        seats[i] = seats[i-1] + seats[i-2];
    
    for (int i=1;i<vip.size();i++)
        ans *= seats[vip[i] - vip[i-1] - 1];

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> N;
    cin >> M;
    vip.push_back(0);
    for (int i=0;i<M;i++) {
        cin >> n;
        vip.push_back(n);
    }
    vip.push_back(N+1);

    dp();
}