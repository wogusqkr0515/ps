#include <iostream>
#include <algorithm>
using namespace std;

int check[10001];

void checkD(int n) {
    int num =n;
    while (n>0) {
        num += n%10;
        n = n/10;
    }
    check[num] = 1;
}

int main() {
    for(int i=1;i<10001;i++) {
        checkD(i);
    }
    for(int i=1;i<10001;i++) {
        if(check[i]==0) cout<<i<<endl;
    }
}