#include <iostream>
using namespace std;

int main() {
    for (int n = 100; n <= 999; ++n) {
        // сотни
        int a = n / 100;
        // десятки
        int b = (n / 10) % 10;
        // единицы
        int c = n % 10;

        if (a + b + c == a * b * c) {
            cout << n << '\n';
        }
    }
}
