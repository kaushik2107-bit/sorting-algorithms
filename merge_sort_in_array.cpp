#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int s, int e) {
    int mid = (s+e)/2;
    int len1 = mid-s+1;
    int len2 = e-mid;

    vector<int> v1(len1);
    vector<int> v2(len2);
    
    int k = s;
    for (int i=0; i<len1; i++) {
        v1[i] = v[k++];
    }

    k = mid+1;
    for (int i=0; i<len2; i++) {
        v2[i] = v[k++];
    }

    int index1 = 0;
    int index2 = 0;
    k = s;

    while(index1 < len1 && index2 < len2) {
        if (v1[index1] > v2[index2]) v[k++] = v2[index2++];
        else v[k++] = v1[index1++];
    }

    while(index1 < len1) {
        v[k++] = v1[index1++];
    }
    while(index2 < len2) {
        v[k++] = v2[index2++];
    }

}

void mergesort(vector<int> &v, int s, int e) {
    if (s >= e) return;

    int mid = (s+e)/2;

    mergesort(v, s, mid);
    mergesort(v, mid+1, e);

    merge(v, s, e);
}

signed main() {
    vector<int> v = {2, 5, 1, 6, 9, 3, 1};

    mergesort(v, 0, v.size()-1);

    for (auto x: v) cout << x << " ";
    cout << endl;
} 