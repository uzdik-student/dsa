/**
 * Математический метод (квадраты): работает за O(√n) и годится даже для больших n (например, 10^9)
 */
#include <iostream>
using namespace std;

int main() {
    int n = 100;

    for (int i = 1; i * i <= n; i++) {
        cout << i * i << " ";
    }
    cout << endl;
}
