/**
 * Given a string, split the string into two substrings at every possible point.
 * The rightmost substring is a suffix. The beginning of the string is the prefix.
 * Determine the lengths of the common prefix between each suffix and the original string.
 * Sum and return the lengths of the common prefixes.
 * Return an array where each element i is the sum for string i.
 * 
 * Example
 * Consider the only string in the array inputs = ['abcabcd').
 * Each suffix is compared to the original string.
 * The sum is 7 + 0 + 0 + 3 + 0 + 0 + 0 = 10
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> computeZ(string &s) {
    int n = s.length();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    z[0] = n; // whole string matches with itself
    return z;
}

vector<int> commonPrefix(vector<string> inputs) {
    vector<int> result;
    for (auto &s : inputs) {
        vector<int> z = computeZ(s);
        int total = 0;
        for (int val : z) total += val;
        result.push_back(total);
    }
    return result;
}

int main() {
    vector<string> inputs = {"abcabcd"};
    vector<int> results = commonPrefix(inputs);
    for (int res : results)
        cout << res << endl;
    return 0;
}
