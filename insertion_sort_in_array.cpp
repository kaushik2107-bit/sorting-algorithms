#include <bits/stdc++.h>
using namespace std;

void insertionsort(vector<int> &v, int val) {
    if (v.size() == 0) {
        v.push_back(val);
        return;
    }
    int ind = 0;
    for (int i=0; i<v.size(); i++) {
        if (v[i] < val) {
            ind = i+1;
        } else break;
    }
    v.insert(v.begin()+ind, val);
}

signed main() {
    vector<int> v;
    
    insertionsort(v, 1);
    insertionsort(v, 20);
    insertionsort(v, -21);
    insertionsort(v, 4);
    insertionsort(v, 10);
    insertionsort(v, 1);

    for (auto x: v) cout << x << ' ';
    cout << endl;

}