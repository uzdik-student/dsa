/**
 * At Nazarbayev University, there are N gamers (1 ≤ N ≤ 300), each of whom must purchase either a PlayStation or an Xbox. The cost of each console varies for each gamer:
 * • A PlayStation for gamer i costs Xi tenge.
 * • An Xbox for gamer i costs Yi tenge.
 * Gamers with the same console can play online together for free.
 * However, if two gamers i and j have different consoles, they must pay Cij tenge to use cross-platform software that allows them to play together.
 * The goal is to minimize the total cost while ensuring that all gamers can play together, either directly (same console) or via cross-platform software.
 * Input Format
 * 1. An integer N - the number of gamers (1 ≤ N ≤ 300).
 * 2. N space-separated integers Xi, X2,..., Xn (Xi ≤ 1000) — the cost of a PlayStation for each gamer.
 * 3. N space-separated integers Yi, Y2, ..., Yn (Yi ≤ 1000) - the cost of an Xbox for each gamer.
 * 4. An N × N symmetric matrix where:
 * • The i-th row consists of N space-separated integers Cij (Cij
 * ≤ 1000).
 * • Cij = Cji (symmetric property).
 * • Cii = O (no cost for self-compatibility).
 * Output Format
 * • Print a single integer — the minimum total cost required to ensure that all gamers can play together.
 */
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 610; // max nodes: 2*N + 2

struct Edge {
    int to, rev;
    int cap;
};

vector<Edge> graph[MAXN];
int level[MAXN], ptr[MAXN];
int source, sink;

void add_edge(int u, int v, int cap) {
    graph[u].push_back({v, (int)graph[v].size(), cap});
    graph[v].push_back({u, (int)graph[u].size() - 1, 0});
}

bool bfs() {
    fill(level, level + MAXN, -1);
    queue<int> q;
    q.push(source);
    level[source] = 0;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (auto &e : graph[v]) {
            if (e.cap > 0 && level[e.to] == -1) {
                level[e.to] = level[v] + 1;
                q.push(e.to);
            }
        }
    }
    return level[sink] != -1;
}

int dfs(int v, int pushed) {
    if (v == sink || pushed == 0) return pushed;
    for (int &cid = ptr[v]; cid < graph[v].size(); cid++) {
        Edge &e = graph[v][cid];
        if (level[v] + 1 != level[e.to] || e.cap <= 0) continue;
        int tr = dfs(e.to, min(pushed, e.cap));
        if (tr == 0) continue;
        e.cap -= tr;
        graph[e.to][e.rev].cap += tr;
        return tr;
    }
    return 0;
}

int dinic() {
    int flow = 0;
    while (bfs()) {
        fill(ptr, ptr + MAXN, 0);
        while (int pushed = dfs(source, INF))
            flow += pushed;
    }
    return flow;
}

int main() {
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    for (int &x : X) cin >> x;
    for (int &y : Y) cin >> y;

    vector<vector<int>> C(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> C[i][j];

    source = 2 * N;
    sink = 2 * N + 1;

    for (int i = 0; i < N; ++i) {
        // source -> PS choice (P_i)
        add_edge(source, i, X[i]);
        // Xbox choice (X_i) -> sink
        add_edge(N + i, sink, Y[i]);
        // PS -> Xbox for each gamer i (unlimited flow)
        add_edge(i, N + i, INF);
    }

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (i != j)
                add_edge(N + i, j, C[i][j]);

    cout << dinic() << endl;
    return 0;
}
