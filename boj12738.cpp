#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1000000];

void sol() {
    vector<int> v;
    v.push_back(arr[0]);

    for (int i=1;i<N;i++) {
        if (arr[i] > v[v.size()-1]) v.push_back(arr[i]);
        else {
            int lo,mid,hi;
            lo = -1; hi = v.size();

            while (lo+1<hi) {
                mid = lo + (hi-lo)/2;
                if (v[mid] >= arr[i]) hi = mid;
                else lo = mid;
            }

            v[hi] = arr[i];
        }
    }

    cout << v.size() << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=0;i<N;i++) 
        cin >> arr[i];

    sol();
}