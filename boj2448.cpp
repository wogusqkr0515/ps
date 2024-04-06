#include <iostream>
#include <algorithm>

using namespace std;

int N;
char tri[3074][6148];

void print() {
    for (int i=0;i<N;i++) {
        for (int j=0;j<2*N-1;j++) {
            cout << tri[i][j];
        }
        cout << '\n';
    }
}

void draw(int row, int col) {
    tri[row][col] = '*';

    tri[row+1][col-1] = '*';
    tri[row+1][col+1] = '*';

    for (int i=0;i<5;i++) tri[row+2][col-2+i] = '*';
    return;
}

void sol(int len, int row, int col) {
    if (len == 3) {
        draw(row, col);
        return;
    }

    sol(len/2, row, col);
    sol(len/2, row+len/2, col-len/2);
    sol(len/2, row+len/2, col+len/2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    fill (&tri[0][0], &tri[N][2*N], ' ');

    sol(N, 0, N-1);
    print();
}