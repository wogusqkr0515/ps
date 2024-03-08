#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;
bool answer[51];
bool isKnow[51];
vector<int> knowPeo[51];
vector<vector<int>> party;

void dfs(int num, int depth) {
    for (int i=0;i<knowPeo[num].size();i++) {
        int idx = knowPeo[num][i];
        answer[idx] = true;
        for (int j=0;j<party[idx].size();j++) {
            if (!isKnow[party[idx][j]]) {
                isKnow[party[idx][j]] = true;
                dfs(party[idx][j], depth+1);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(answer, false, sizeof(answer));
    memset(isKnow, false, sizeof(isKnow));

    int trueNum, n, val;
    cin >> N >> M;
    cin >> trueNum;
    for (int i=0;i<trueNum;i++) {
        cin >> val;
        isKnow[val] = true;
    }
    for (int i=0;i<M;i++) {
        vector<int> iter;
        cin >> n;
        for (int j=0;j<n;j++) {
            cin >> val;
            iter.push_back(val);
            knowPeo[val].push_back(i);
        }
        sort(iter.begin(), iter.end());
        party.push_back(iter);
    }
    if (trueNum == 0) cout << M;
    else {
        for (int i=1;i<=N;i++) {
            if (isKnow[i]) {
                dfs(i, 0);
            }
        }
        int cnt = 0;
        for (int i=0;i<M;i++) {
            if (!answer[i]) cnt++;
        }
        cout << cnt;
    }
}