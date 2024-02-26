#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Coord {
    int x, y;
    Coord(int xx, int yy): x(xx), y(yy) {}; 
};

bool cmp (Coord a, Coord b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int main() {
    int n, x, y;
    vector<Coord> arr;

    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> x >> y;
        arr.push_back(Coord(x, y));
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i=0;i<n;i++) {
        cout << arr[i].x << " " << arr[i].y << '\n';
    }
}