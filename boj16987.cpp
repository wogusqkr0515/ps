#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct egg {
    int s, w;
} Egg;

int N, ans;
Egg eggs[8];

void sol(int idx) {
    if (idx == N) {
        int cnt = 0;
        for (int i=0;i<N;i++) {
            if (eggs[i].s <=0) cnt++;
        }
        if (cnt > ans) ans = cnt; // idx 가 N이고 cnt가 전역변수 ans보다 클 경우 갱신
        return;
    }
    // 현재 잡은 계란이 깨진 계란인 경우 탐색 안하고 바로 오른쪽 계란
    if (eggs[idx].s<=0) return sol(idx+1);

    bool flag = false;

    // 탐색
    for (int i=0;i<N;i++) {
        if (i==idx) continue;
        
        if (eggs[i].s>0) {
            eggs[idx].s -= eggs[i].w;
            eggs[i].s -= eggs[idx].w;
            
            flag = true;
            sol(idx+1);
            
            eggs[idx].s += eggs[i].w;
            eggs[i].s += eggs[idx].w;
        }
    }
    // 탐색 완료 후 cnt 값 갱신을 위해 
    if (!flag) sol(idx+1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ans = 0;
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> eggs[i].s;
        cin >> eggs[i].w;
    }
    sol(0);
    cout << ans;
}