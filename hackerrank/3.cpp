#include <bits/stdc++.h>
using namespace std;

// Array representaion of segment tree
vector<long long> tree;

// Build segment tree
void build(int a[], int pos, int low, int high) {
    if (low == high) {
        tree[pos] = a[low];
    } else {
        int mid = (low + high) / 2;
        build(a, 2*pos+1, low, mid);
        build(a, 2*pos+2, mid+1, high);
        tree[pos] = tree[2*pos+1] + tree[2*pos+2];
    }
}

// Update segment tree
void update(int pos, int low, int high, int index, int value) {
    if (low == high) {
        tree[pos] = value;
    } else {
        int mid = (low + high) / 2;
        if (index <= mid) {
            update(2*pos+1, low, mid, index, value);
        } else {
            update(2*pos+2, mid+1, high, index, value);
        }
        tree[pos] = tree[2*pos+1] + tree[2*pos+2];
    }
}

// Query segment tree
long long sum(int pos, int low, int high, int qlow, int qhigh) {
    if (qhigh < low || qlow > high) {
        // no overlap
        return 0;
    }
    
    if (qlow <= low && high <= qhigh) { 
        // total overlap
        return tree[pos];
    }
    
    // partial overlap
    int mid = (low + high) / 2;
    long long left_sum = sum(2 * pos + 1, low, mid, qlow, qhigh);
    long long right_sum = sum(2 * pos + 2, mid + 1, high, qlow, qhigh);
    return left_sum + right_sum;
}

int main() {
    int n, q;
    cin >> n >> q;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Build segment tree
    tree.resize(4 * n);
    build(arr, 0, 0, n-1);
    
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k, u;
            cin >> k >> u;
            // Update segment tree
            update(0, 0, n-1, k-1, u);
        } else {
            int a, b;
            cin >> a >> b;
            // Query segment tree
            cout << sum(0, 0, n-1, a-1, b-1) << ' ';
        }
    }
    cout << endl;
}