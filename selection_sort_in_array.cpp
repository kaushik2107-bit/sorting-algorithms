#include <bits/stdc++.h>
using namespace std;

void selection_sort_in_array(vector<int> &v) {
    for (int i=0; i<v.size()-1; i++) {
        int temp = v[i];
        int index= i;
        for (int j=i+1; j<v.size(); j++) {
            if (v[j] < v[index]) {
                index = j;
            }
        }
        swap(v[i], v[index]);
    }
}

signed main() {
    vector<int> v = {1, 33, 2, 453 , 567 , 21, 3562, 1, 12, 11};
    selection_sort_in_array(v);
    
    for (auto x: v) cout << x << " ";
    cout << endl;
}