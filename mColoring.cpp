#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isSafe(int node, int color[], vector<vector<int>> &graph, int n, int col)
    {
        for (int i = 0; i < n; i++)
        {
            if (graph[node][i] == 1 && color[i] == col)
            {
                return false;
            }
        }
        return true;
    }
    bool solve(int node, int color[], int m, int n, vector<vector<int>> &graph)
    {
        if (node == n)
            return true;
        for (int i = 1; i <= m; i++)
        {
            if (isSafe(node, color, graph, n, i))
            {
                color[node] = i;
                if (solve(node + 1, color, m, n, graph))
                    return true;
                color[node] = 0;
            }
        }
        return false;
    }
    bool graphColoring(int v, vector<pair<int, int>> &edges, int m)
    {
        vector<vector<int>> graph(v, vector<int>(v, 0));
        for (auto &edge : edges)
        {
            graph[edge.first][edge.second] = 1;
            graph[edge.second][edge.first] = 1;
        }
        int color[v] = {0};
        return solve(0, color, m, v, graph);
    }
};
int main()
{
    int v, e, m;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;
    vector<pair<int, int>> edges;
    cout << "Enter the edges (0-based index):\n";
    for (int i = 0; i < e; i++)
    {
        int u, v2;
        cin >> u >> v2;
        edges.push_back({u, v2});
    }
    cout << "Enter number of colors: ";
    cin >> m;
    Solution sol;
    if (sol.graphColoring(v, edges, m))
    {
        cout << "Graph can be colored with " << m << " colors.\n";
    }
    else
    {
        cout << "Graph cannot be colored with " << m << " colors.\n";
    }
    return 0;
}
