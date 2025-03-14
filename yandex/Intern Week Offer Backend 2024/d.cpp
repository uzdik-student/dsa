/**
 * https://contest.yandex.ru/contest/69109/problems/D/
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n) {
    if (n == 1) {
        return false;
    }

    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

vector<long long> buildPrimes(int limit) {
    vector<long long> primes;
    for (long long i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }
    return primes;
}

vector<bool> sieve(int n) {
    vector<bool> primes(n + 1, true);
    primes[0] = primes[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }
    
    return primes;
}

int main() {
    int t;
    cin >> t;

    int limit = 10000000;
    vector<bool> sv = sieve(limit);
    // vector<int> primes = buildPrimes(limit);
    vector<int> primes;
    for (int i = 2; i <= limit; i++) {
        if (sv[i]) {
            primes.push_back(i);
        }
    }

    while (t--) {
        long long a, b;
        cin >> a >> b;

        long long answer = gcd(a, b);

        for (int p : primes) {
            answer = max(answer, gcd(a * p, b));
            answer = max(answer, gcd(a, b * p));
        }

        cout << answer << endl;
    }
}