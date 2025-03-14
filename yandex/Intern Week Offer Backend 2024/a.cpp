/**
 * https://contest.yandex.ru/contest/69109/problems/A/
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];
    int largest = INT_MIN;
    bool possible = true;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        largest = max(largest, a[i]);
        if (i > 0 && a[i-1] > a[i]) {
            possible = false;
        }
    }


    if (!possible) {
        cout << -1 << endl;
    } else if (n == 1) {
        cout << 0 << endl;
    } else {
        cout << largest - a[0] << endl;
    }
}

