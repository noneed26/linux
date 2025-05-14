#include <iostream>
#include <vector>
using namespace std;

#define max 999

class prims
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

    void MST()
    {
        for (int i = 0; i < V - 1; i++)
        {
            int minVertex = findMinDistance(dist, vis);
            vis[minVertex] = true;

            // compare for the lowest value between dist and minVertex row, and replace it with minimum
            for (int i = 0; i < V; i++)
            {
                if (!vis[i] && arr[minVertex][i] < dist[i])
                {
                    dist[i] = arr[minVertex][i];
                    from[i] = minVertex;
                }
            }
        }
    }

    void printMST()
    {
        int mstCost = 0;
        cout << "MST is: \n";
        for (int i = 0; i < V; i++)
        {
            int u = from[i];
            int v = i;

            if (u != v)
            {
                mstCost = mstCost + arr[u][v];
                cout << u << "," << v << ":" << arr[u][v] << endl;
            }
        }
        cout << "MST cost is: " << mstCost << endl;
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

    prims ob;
    ob.adjMatrix(V);
    ob.printAdjMatrix();
    ob.initialization(src);
    ob.MST();
    ob.printMST();
    return 0;
}
