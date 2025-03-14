#include <iostream>
#include <vector>
#include <unordered_map>
#include <random>

struct FireFighter
{
    int x, y, P;
};

std::unordered_map <int, std::pair <FireFighter, std::vector <int>>> graph;


bool IsInsideRadius(int x1, int y1, int x2, int y2, int P1)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= P1 * P1 ?
        true : false;
}


std::unordered_map <int, bool> visited;

int dfs(int i)
{
    visited[i] = true;  
    int count = 1;

    for (const int& j : graph[i].second)
    {
        if (!visited[j])
        {
            count += dfs(j);
        }
    }

    return count;
}

int MaximumFireFightersInNetwork()
{
    int N;
    int x, y, P;

    std::cin >> N;

    // G = (V, {})

    for (int i = 0; i < N; i++)
    {
        std::cin >> x >> y >> P;
        FireFighter cur{ x, y, P };
        graph.insert({ i, { cur, {} } });
    }

    for (int i = 0; i < N; i++)
    {
        for (auto& [vertex, info] : graph)
        {
            if (vertex == i) { continue; }
            if (IsInsideRadius(info.first.x, info.first.y, graph[i].first.x, graph[i].first.y, info.first.P))
            {
                info.second.push_back(i); // first
            }
            if (IsInsideRadius(graph[i].first.x, graph[i].first.y, info.first.x, info.first.y, graph[i].first.P))
            {
                graph[i].second.push_back(vertex);
            }
        }
    }

    int max_firefighters = 0;
    for (int i = 0; i < N; i++)
    {
        max_firefighters = std::max(max_firefighters, dfs(i));
        visited.clear();
    }
    return max_firefighters; 

    // 0 <= N <= 200
}

/*
Test Case:
4
1 3 5
5 4 3
7 2 1
6 1 1

Output: 3
*/

int main()
{
    std::cout << MaximumFireFightersInNetwork();
    return 0;
}
