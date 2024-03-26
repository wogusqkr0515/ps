#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
int adj[30][2];
char zero = 'A', dot = '.';
string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void pre(int idx) {
    cout << str[idx];
    
    if (adj[idx][0] != -1) pre(adj[idx][0]);
    if (adj[idx][1] != -1) pre(adj[idx][1]);
}

void in(int idx) {
    if (adj[idx][0] != -1) in(adj[idx][0]);
    cout << str[idx];
    if (adj[idx][1] != -1) in(adj[idx][1]);
}

void post(int idx) {
    if (adj[idx][0] != -1) post(adj[idx][0]);
    if (adj[idx][1] != -1) post(adj[idx][1]);
    cout << str[idx];
}

void sol() {
    pre(0);
    cout << '\n';
    in(0);
    cout << '\n';
    post(0);
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(&adj[0][0], &adj[26][2], -1);

    char a, b, c;
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> a >> b >> c;
        if (b!=dot)
            adj[a-zero][0] = b-zero;
        if (c!=dot)
            adj[a-zero][1] = c-zero;
    }

    sol();
}