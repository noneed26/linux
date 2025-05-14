#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 999999

class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

class Kruskal
{
private:
    vector<Edge> edges;
    vector<int> parent;
    int V;

public:
    void inputGraph(int V)
    {
        this->V = V;
        int e;
        cout << "Enter number of edges: ";
        cin >> e;

        for (int i = 0; i < e; i++)
        {
            int u, v, w;
            cout << "Enter edge " << i + 1 << " (u v w): ";
            cin >> u >> v >> w;
            edges.push_back(Edge(u, v, w));
        }
    }

    int find(int i)
    {
        while (i != parent[i])
        {
            i = parent[i]; // Move up until root
        }
        return i;
    }

    void unite(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);
        if (pu != pv)
        {
            parent[pu] = pv; // Merge u's set with v's set
        }
    }

    void kruskalMST()
    {
        parent.resize(V);
        for (int i = 0; i < V; i++)
        {
            parent[i] = i; // Each node is initially its own parent
        }

        sort(edges.begin(), edges.end(), [](Edge a, Edge b)
             { return a.w < b.w; });

        int mstCost = 0;
        cout << "Edges in MST:\n";

        for (Edge edge : edges)
        {
            int u = edge.u;
            int v = edge.v;
            int w = edge.w;

            if (find(u) != find(v))
            {
                unite(u, v);
                mstCost += w;
                cout << u << " - " << v << " : " << w << endl;
            }
        }

        cout << "Total cost of MST: " << mstCost << endl;
    }
};

int main()
{
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    Kruskal k;
    k.inputGraph(V);
    k.kruskalMST();

    return 0;
}
