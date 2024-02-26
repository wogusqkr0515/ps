#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Pair {
    int age, idx;
    string name;
    Pair(int a, string n, int i): age(a), name(n), idx(i) {};
};

bool cmp (Pair a, Pair b) {
    if (a.age == b.age) return a.idx < b.idx;
    return a.age < b.age;
}

int main() {
    int n, val;
    string s;
    vector<Pair> arr;

    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> val >> s;
        arr.push_back(Pair(val, s, i));
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i=0;i<n;i++) {
        cout << arr[i].age << " " << arr[i].name << '\n';
    }
}