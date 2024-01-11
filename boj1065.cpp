#include <iostream>
using namespace std;

int answer;

void getAnswer(int num) {
    if (num == 1000) return;
    if (100 > num) {
        answer++;
        return;
    }
    int hundred, ten, one;
    one = num %10;
    num = num / 10;
    ten = num %10;
    hundred = num / 10;
    if ( (hundred - ten) == (ten - one)) answer++;
}

int main() {
    int N;
    answer = 0;

    cin >> N;
    for (int i=1;i<N+1;i++) {
        getAnswer(i);
    }
    cout << answer << endl;
}