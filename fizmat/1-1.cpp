#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int p[] = {1, 2, 3};

    do {
        cout << p[0] * 100 + p[1] * 10 + p[2] << '\n';
    } while (next_permutation(p, p + 3));
}
