#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Score {
    int kor, math, eng;
    string name;
    Score(string n, int k, int e, int m): name(n), kor(k), eng(e), math(m) {};
};

bool cmp(Score a, Score b) {
    if (a.kor != b.kor) return a.kor > b.kor;
    if (a.eng != b.eng) return a.eng < b.eng;
    if (a.math != b.math) return a.math > b.math;
    return a.name < b.name;
}

int main() {
    int N, a, b, c;
    string str;
    vector<Score> arr;

    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> str >> a >> b >> c;
        arr.push_back(Score(str, a, b, c));
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i=0;i<N;i++) cout << arr[i].name << '\n';
}
