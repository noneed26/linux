#include <iostream>
#include <vector>
using namespace std;
#define MAX 999
struct edgeList
{
    int u, v, wt; // Source, Destination, Weight
};
class bellmanFord
{
public:
    int V, E;               // Number of vertices and edges
    vector<edgeList> edges; // Edge list
    void inputGraph()
    {
        cout << "Enter number of vertices and edges: ";
        cin >> V >> E;
        edges.resize(E);
        cout << "Enter edges (u v weight):" << endl;
        for (int i = 0; i < E; i++)
        {
            cin >> edges[i].u >> edges[i].v >> edges[i].wt;
        }
    }
    // Bellman-Ford Algorithm
    vector<int> bellman_ford(int S)
    {
        vector<int> dist(V, MAX); // Initialize distances to MAX (infinity)
        dist[S] = 0;              // Source vertex distance is 0
        // Relaxation for (V-1) times
        for (int i = 0; i < V - 1; i++)
        {
            for (auto edge : edges)
            {
                int u = edge.u;
                int v = edge.v;
                int wt = edge.wt;
                if (dist[u] != MAX && dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        // Check for negative weight cycle
        for (auto edge : edges)
        {
            int u = edge.u;
            int v = edge.v;
            int wt = edge.wt;
            if (dist[u] != MAX && dist[u] + wt < dist[v])
            {
                cout << "Negative weight cycle detected." << endl;
                return {-1};
            }
        }
        return dist;
    }
    void printResult(vector<int> dist)
    {
        if (dist[0] == -1)
            return; // -ve cycle case
        cout << "Vertex Distance from Source" << endl;
        for (int i = 0; i < V; i++)
        {
            cout << i << "\t";
            if (dist[i] == MAX)
            {
                cout << "INF";
            }
            else
            {
                cout << dist[i];
            }
            cout << endl;
        }
    }
};
int main()
{
    bellmanFord graph;
    graph.inputGraph();
    int source;
    cout << "Enter source vertex: ";
    cin >> source;
    vector<int> result = graph.bellman_ford(source);
    graph.printResult(result);
    return 0;
}