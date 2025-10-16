#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, a;
  cin >> a >> n;;
  long long sum = 1;
  long long x = 1;
  for (long long i=1; i<=n; i++) {
    x = x * a;
    sum += x;
  }
  cout << sum << endl;
}