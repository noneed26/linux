#include <iostream>
#include <vector>
using namespace std;

#define max 999

class dijkstra
{
private:
    vector<vector<int>> arr;
    vector<int> dist;
    vector<bool> vis;
    vector<int> from;
    int V;

public:
    void adjMatrix(int V)
    {
        this->V = V;
        arr.resize(V, vector<int>(V));

        cout << "Enter graph: \n";

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                cout << i << "," << j << " : ";
                cin >> arr[i][j];
                if (arr[i][j] == 0)
                {
                    arr[i][j] = max;
                }
            }
        }
    }

    void printAdjMatrix()
    {
        cout << "Adj Matrix is: \n";

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    void initialization(int src) // src is source vertex
    {
        dist.resize(V, max);
        vis.resize(V, false);
        from.resize(V, src);

        for (int j = 0; j < V; j++)
        {
            dist[j] = arr[src][j];
        }

        dist[src] = 0;
        vis[src] = true;
    }

    void dijkstraMain()
    {
        for (int i = 0; i < V - 1; i++)
        {
            int minVertex = findMinDistance(dist, vis);
            vis[minVertex] = true;

            for (int j = 0; j < V; j++)
            {
                // Check if the neighbor is unvisited and if there's an edge between minVertex and j
                if (!vis[j] && arr[minVertex][j] != max)
                {
                    // If the new path to j is shorter, update the distance and from value
                    if (dist[j] > dist[minVertex] + arr[minVertex][j])
                    {
                        dist[j] = dist[minVertex] + arr[minVertex][j];
                        from[j] = minVertex;
                    }
                }
            }
        }
    }

    void printMST()
    {
        cout << "Paths and costs from source vertex " << from[0] << " to every destination vertex:\n";
        
        for (int i = 0; i < V; i++)
        {
            if (i != from[0]) // Skip printing for the source itself
            {
                int u = i;
                vector<int> path;
                int totalCost = dist[i];

                // Reconstruct the path from the destination to the source using the 'from' array
                while (u != from[u])
                {
                    path.push_back(u);
                    u = from[u];
                }
                path.push_back(from[u]);

                // Print the path from source to destination
                cout << "Path to " << i << ": ";
                for (int j = 0; j < path.size(); j++)
                {
                    cout << path[j];
                    if (j != path.size() - 1) cout << " -> ";
                }
                cout << " | Cost: " << totalCost << endl;
            }
        }
    }

    int findMinDistance(const vector<int> &dist, const vector<bool> &vis)
    {
        int min = max;
        int minIndex = -1;

        for (int i = 0; i < dist.size(); i++)
        {
            if (!vis[i] && dist[i] < min)
            {
                min = dist[i];
                minIndex = i;
            }
        }

        return minIndex;
    }
};

int main()
{
    int V, src;
    cout << "Enter number of vertices: \n";
    cin >> V;
    cout << "Enter source vertex: \n";
    cin >> src;

    dijkstra ob;
    ob.adjMatrix(V);
    ob.printAdjMatrix();
    ob.initialization(src);
    ob.dijkstraMain();
    ob.printMST();
    return 0;
}
