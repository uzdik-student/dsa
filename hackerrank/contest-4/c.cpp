/**
 * The ancient library of Astana contains N chambers connected by a network of M one-way tunnels, forming a Directed Acyclic Graph (DAG). 
 * A young cartographer, Leila, wishes to find the total number of distinct paths she can take to travel from the first chamber to the Nth chamber using these tunnels. 
 * Given that she has a map detailing all the directed tunnel connections between the chambers, calculate the total count of unique routes from chamber 1 to chamber N that Leila can follow.
 * 
 * INPUT FORMAT
 * The first input line has two integers N and M: the number of chambers and one-way tunnels. The levels are numbered 1,2,...,N.
 * After this, there are M lines describing the tunnels. Each line has two integers a and b: there is a tunnel from chamber a to chamber b.
 * 
 * OUTPUT FORMAT
 * Print one integer: the number of ways Leila can take to travel from chamber 1 to chamber N. Since the result may be large, print it modulo 10°+7.
 */
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

vector<vector<int>> adj; // adjacency list for the graph
vector<int> inDegree; // to store in-degrees of each node
vector<long long> dp; // dp[i] will store the number of ways to reach node i

void topologicalSort(int N) {
    queue<int> q;

    // Start with nodes that have zero in-degree
    for (int i = 1; i <= N; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Process all the neighbors of u
        for (int v : adj[u]) {
            dp[v] = (dp[v] + dp[u]) % MOD; // Update the number of ways to reach v
            inDegree[v]--; // Decrease the in-degree of v

            if (inDegree[v] == 0) {
                q.push(v); // If the in-degree of v becomes 0, add it to the queue
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    adj.resize(N + 1);
    inDegree.resize(N + 1, 0);
    dp.resize(N + 1, 0);

    // Read in the tunnels
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b); // Tunnel from a to b
        inDegree[b]++; // Increase the in-degree of b
    }

    // Start with chamber 1
    dp[1] = 1;

    // Perform topological sorting and DP update
    topologicalSort(N);

    // The answer is the number of ways to reach chamber N
    cout << dp[N] << endl;

    return 0;
}
