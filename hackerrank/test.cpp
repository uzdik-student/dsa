#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        // Проверяем четность чисел
        if ((a % 2 == b % 2) && (b % 2 == c % 2)) {
            // Если все числа имеют одинаковую четность
            cout << "1 1 1" << endl;
        } else {
            // Если хотя бы одно число имеет другую четность
            cout << "0 0 0" << endl;
        }
    }

    return 0;
}
