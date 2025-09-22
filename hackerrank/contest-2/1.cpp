/**
 * A large company with multiple data centers spread across the city has decided to shut down operations temporarily to upgrade its infrastructure.
 * The company's network consists of N data centers connected with M bidirectional communication links between some pairs of data centers.
 * To perform the upgrade, the IT team plans to close one data center at a time.
 * When a data center is closed, all communication links connected to that data center also shut down and can no longer be used.
 * The IT team is interested in knowing at each point in time (initially, and after each closing) whether the network is "fully connected" - meaning that it is possible to communicate from any current data center to any other data center along an appropriate series of communication links.
 * Since the company's network is initially in a somewhat degraded state, it may not even start out fully connected.
 * 
 * Input format:
 * The first linke of input contains N and M.
 * Each of the next M lines each describes a bidirectional connection between two data centers (data centercs are conveniently numbered 1...N).
 * The final N lines give a permutation of 1...N describing the order in which the data centers will be closed.
 * 
 * Output format:
 * The output consists of N lines, each containing "YES" or "NO".
 * The first line indicates whether the initial network is fully connected, and line i+1 indicates whether the network is fully connected after the i-th closing.
 * 
 * Constraints:
 * 1 <= N, M <= 3000
 */
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 3000;

vector<int> parent(MAX_N + 1, -1);
vector<vector<int>> neighbors(MAX_N + 1);
vector<bool> active(MAX_N + 1, false);
vector<string> results;

int find(int v) {
    if (parent[v] < 0) {
        return v;
    }
    
    return find(parent[v]);
}

void union_sets(int a, int b) {
    if (parent[a] > parent[b]) {
        swap(a, b);
    }
    parent[a] += parent[b];
    parent[b] = a;
}

int main() {
    int N, M;
    cin >> N >> M;

    // Read the graph edges
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        neighbors[u].push_back(v);
        neighbors[v].push_back(u);
    }

    vector<int> shutdownOrder(N);
    for (int i = 0; i < N; i++) {
        cin >> shutdownOrder[i];
    }
    reverse(shutdownOrder.begin(), shutdownOrder.end());

    int connected = 0;
    for (int node : shutdownOrder) {
        active[node] = true;
        connected++;

        for (int neighbor : neighbors[node]) {
            if (active[neighbor]) {
                int a = find(node);
                int b = find(neighbor);
                if (a != b) {
                    union_sets(a, b);
                    connected--;
                }
            }
        }

        results.push_back(connected == 1 ? "YES" : "NO");
    }

    reverse(results.begin(), results.end());
    for (string res : results) {
        cout << res << endl;
    }
}