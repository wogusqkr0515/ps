#include <iostream>
#include <algorithm>
using namespace std;



int main() {
    pair<int, int> arr[50];
    int N, w, h;

    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> w >> h;
        arr[i].first = w; arr[i].second = h;
    }
    for (int i=0;i<N;i++) {
        int rank = 1;
        for (int j=0;j<N;j++) {
            if(arr[i].first < arr[j].first && arr[i].second < arr[j].second) rank++;
        }
        cout << rank << " ";
    }
}