#include <bits/stdc++.h>
using namespace std;

void bubble_sort_in_array(vector<int> &v) {
    for (int i=0; i<v.size()-1; i++) {
        for (int j=i+1; j<v.size(); j++) {
            if (v[i] > v[j]) swap(v[i], v[j]);
        }
    }
}

signed main() {
    vector<int> v = {4, 23, 12, 10, 1, 13, 2, 100, 65};
    bubble_sort_in_array(v);
    for (auto x: v) cout << x << " ";
    cout << endl;
}