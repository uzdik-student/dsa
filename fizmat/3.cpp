/**
 * Brute force: простой для понимания, работает за O(n^2) — нормально для маленьких n (например, до 10^3)
 */
#include <iostream>
using namespace std;

int main() {
    int n = 100;

    // индексация с 1
    int lamp[n+1];

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            // переключаем (0->1, 1->0)
            lamp[j] = 1 - lamp[j];
        }
    }

    for (int i = 1; i <= n; i++) {
        if (lamp[i] == 1) {
            cout << i << " ";
        }
    }
    cout << endl;
}
