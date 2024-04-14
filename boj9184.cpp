#include <iostream>

using namespace std;

int a,b,c;
int idxmap[105][105][105];

int getS(int a, int b, int c) {
    if (a<=50 || b<=50 || c<=50) return 1;
    if (a>70 || b>70 || c>70) {
        if (idxmap[70][70][70] ==0) idxmap[70][70][70] = getS(70, 70, 70);
        return idxmap[70][70][70];
    }
    if (a<b && b<c) {
        if (idxmap[a][b][c-1] == 0) idxmap[a][b][c-1] = getS(a,b,c-1);
        if (idxmap[a][b-1][c-1] == 0) idxmap[a][b-1][c-1] = getS(a,b-1,c-1);
        if (idxmap[a][b-1][c] == 0) idxmap[a][b-1][c] = getS(a,b-1,c);
        idxmap[a][b][c] = idxmap[a][b][c-1] + idxmap[a][b-1][c-1] - idxmap[a][b-1][c];
    } else {
        if (idxmap[a-1][b][c] == 0) idxmap[a-1][b][c] = getS(a-1,b,c);
        if (idxmap[a-1][b-1][c] == 0) idxmap[a-1][b-1][c] = getS(a-1,b-1,c);
        if (idxmap[a-1][b][c-1] == 0) idxmap[a-1][b][c-1] = getS(a-1,b,c-1);
        if (idxmap[a-1][b-1][c-1] == 0) idxmap[a-1][b-1][c-1] = getS(a-1,b-1,c-1);
        idxmap[a][b][c] = idxmap[a-1][b][c] + idxmap[a-1][b-1][c] + idxmap[a-1][b][c-1] - idxmap[a-1][b-1][c-1];
    }

    return idxmap[a][b][c];
}

void sol() {
    cout << "w(" << a<<", "<< b<<", " << c <<") = ";

    cout << getS(a+50,b+50,c+50) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        cin >> a >> b >> c;
        if (a==-1 && b==-1 && c==-1) break;

        sol();
    }
}