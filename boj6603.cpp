#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> K;
vector<vector<int>> nums;
int lot[6] = {0,};
int visited[13] = {0,};

void sol(int start, int step, int idx) {
    if (step == 6) {
        for (int i=0;i<step;i++) cout << lot[i] << " ";
        cout << '\n';
        return;
    }

    for (int i=start;i<K[idx];i++) {
        // if (i > K[idx] - 6 + step) break;
        if (!visited[i]) {
            // cout << "idx " << idx << " step " << step << " i " << nums[idx][i] << endl;
            lot[step] = nums[idx][i];
            visited[i] = 1;
            sol(i+1, step+1, idx);
            visited[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, val;
    k = -1;
    
    while (k!=0) {
        cin >> k;
        vector<int> num;
        K.push_back(k);
        for (int i=0;i<k;i++) {
            cin >> val;
            num.push_back(val);
        }
        if (k > 0) nums.push_back(num);
    }
    for (int i=0;i<K.size();i++) {
        // cout << K[i] << endl;
        memset(lot, 0, 6);
        memset(visited, 0, 13);
        sol(0, 0, i);
        cout << '\n';
    }
    
}


/*
compile error  -- why??

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> K;
vector<vector<int>> nums;
int lot[6] = {0,};
int visited[13] = {0,};

void sol(int step, int idx) {
    if (step == 6) {
        for (int i=0;i<step;i++) cout << lot[i] << " ";
        cout << '\n';
        return;
    }

    for (int i=0;i<K[idx];i++) {
        if (i > K[idx] - 6 + step) break;
        if (!visited[i]) {
            // cout << "idx " << idx << " step " << step << " i " << nums[idx][i] << endl;
            lot[step] = nums[idx][i];
            visited[i] = 1;
            sol(step+1, idx);
            visited[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, val;
    k = -1;
    
    while (k!=0) {
        cin >> k;
        vector<int> num;
        K.push_back(k);
        for (int i=0;i<k;i++) {
            cin >> val;
            num.push_back(val);
        }
        if (k > 0) nums.push_back(num);
    }
    for (int i=0;i<K.size();i++) {
        cout << K[i] << endl;
        memset(lot, 0, 6);
        memset(visited, 0, 13);
        sol(0, i);
    }
    
}
*/