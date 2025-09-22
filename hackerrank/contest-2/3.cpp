/**
 * Find the number of string of a given length that can be formed under the following rules:
 * 
 * Each letter is a vowel, that is, it is in the set {'a', 'e', 'i', 'o', 'u'}
 * The letter 'a' may only be followed by the letter 'e'.
 * An 'e' may only be followed by an 'a' or an 'i'.
 * An 'i' may not be next to another 'i'.
 * The letter 'o' may only be followed by an 'i' or a 'u'.
 * The letter 'u' may only be followed by an 'a'.
 * 
 * Example:
 * To illustrate some of the rules, start with the string s='a' and build to the right.
 * 1. 'a' may only be followed by 'e', so the new string can be 'ae'.
 * 2. 'ae' may only be followed by 'a' or 'i', so the new string can be 'aea' or 'aei'.
 * 3. 'aea' must be 'aeae' next, and 'aei' can be 'aeia', 'aeie', 'aeio', or 'aeiu' because 'i' cannot follow another 'i'.
 * 
 * Analyses of lengths of strings up to 3 are in the samples below. Since the number of permutations might be very large, return the value module (10^9+7)
 * 
 * Function description:
 * Complete the countPerms function in the editor below.
 * countPerms has the following parameter: int n: the length of string to analyze
 * Returns: int: the number of permutations, module (10^9+7)
 * 
 * Constrains:
 * 0 < n < 10^5
 */

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int countPerms(int n) {
    vector<long long> dp(5, 1);
    vector<long long> temp(5, 0);

    for (int i = 2; i <= n; i++) {
        temp[0] = dp[1] % MOD;
        temp[1] = (dp[0] + dp[2]) % MOD;
        temp[2] = (dp[0] + dp[1] + dp[3] + dp[4]) % MOD;
        temp[3] = (dp[2] + dp[4]) % MOD;
        temp[4] = dp[0] % MOD;

        dp = temp;
    }

    return (dp[0] + dp[1] + dp[2] + dp[3] + dp[4]) % MOD;
}

int main() {
    int n;
    cin >> n;
    cout << countPerms(n) << endl;
}

