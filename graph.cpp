#include <iostream>
#include <list>
#include <vector>
#include<queue>
#include<stack>
using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printList()
    {
        for(int i=0; i<V; i++)
        {
            cout<<i<<": ";
            for(int neighbor : l[i])
            {
                cout<<neighbor<<" ";
            }
            cout<<endl;
        }
    }

    void BFS()
    {
        queue<int> Q;
        vector<bool> vis(V, false);

        Q.push(0);
        vis[0] = true;

        while(!Q.empty())
        {
            int u = Q.front(); // current vertex
            Q.pop();
            cout<<u<<" ";
            
            for(int neighbor : l[u])
            {
                if(!vis[neighbor])
                {
                    vis[neighbor] = true;
                    Q.push(neighbor);
                }
            }
        }
    }

    void DFS()
    {
        stack<int> S;
        vector<bool> vis(V, false);

        S.push(0);

        while(!S.empty())
        {
            int u = S.top();
            S.pop();

            if(!vis[u])
            {
                vis[u] = true;
                cout<<u<<" ";

                for(int neighbor : l[u])
                {
                    if(!vis[neighbor])
                    {
                        S.push(neighbor);
                    }
                }
            }
        }
    }
    ~Graph()
    {
        delete[] l;
    }
};

int main()
{
    int V,E;
    cout<<"Enter nuumber of vertex & edges: \n";
    cin>>V>>E;

    Graph ob(V);

    cout<<"Enter (u,v) edges: \n";
    int u,v;
    for(int i=0; i<E; i++)
    {
        cin>>u>>v;
        ob.addEdge(u,v);
    }

    cout<<"Adjacency list is: \n";
    ob.printList();

    cout<<"BFS is: \n";
    ob.BFS();

    cout<<"DFS is: \n";
    ob.DFS();
    return 0;
}