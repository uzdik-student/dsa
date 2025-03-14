#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int numPaths(vector<vector<int>> &warehouse) {
    int n, m;
    n = warehouse.size();
    m = warehouse[0].size();
    
    int dp[n+1][m+1] = {};
    dp[1][1] = 1;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (i==1 && j==1) {
                continue;
            }
            if (warehouse[i-1][j-1]) {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return dp[n][m];
}

int main() ... 