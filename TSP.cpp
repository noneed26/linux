#include <iostream>
#include <vector>
#include <algorithm>

const int MAX = 99999;
using namespace std;

class TSP
{
    vector<vector<int>> matrix;
    vector<int> path;
    int MinCost, start;
    int n;

    int ReduceMatrix(vector<vector<int>> Matrix, int choice)
    {
        int mincost = 0;

        for (int i = 0; i < n; i++)
        {
            int minvalue = *min_element(Matrix[i].begin(), Matrix[i].end());
            if (minvalue != MAX)
            {
                for (int j = 0; j < n; j++)
                {
                    if (Matrix[i][j] != MAX)
                    {
                        Matrix[i][j] = Matrix[i][j] - minvalue;
                    }
                }
                mincost += minvalue;
            }
        }

        for (int i = 0; i < n; i++)
        {
            int minvalue = MAX;

            for (int j = 0; j < n; j++)
            {
                if (Matrix[j][i] < minvalue)
                {
                    minvalue = Matrix[j][i];
                }
            }

            if (minvalue != MAX)
            {
                for (int j = 0; j < n; j++)
                {
                    if (Matrix[j][i] != MAX)
                    {
                        Matrix[j][i] = Matrix[j][i] - minvalue;
                    }
                }
                mincost += minvalue;
            }
        }

        if (choice == 1)
        {
            matrix = Matrix;
        }

        return mincost;
    }

public:
    TSP(int x)
    {
        n = x;
        matrix.resize(n, vector<int>(n, MAX));
        path.resize(n, MAX);
    }

    void read()
    {
        int w;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "Enter the weight of edge " << i << "-> " << j << " (-1 for no edge): ";
                cin >> w;
                if (w == -1)
                {
                }
                else
                {
                    matrix[i][j] = w;
                }
            }
        }
    }

    void show()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void tspsol()
    {
        MinCost = ReduceMatrix(matrix, 1);
        cout << "Enter the start node: ";
        cin >> start;
        path[0] = start;
        int index = 1;
        int pre = start, next, min = MAX;
        vector<vector<int>> copy;

        for (int z = 0; z < n - 1; z++)
        {
            for (int l = 0; l < n; l++)
            {
                if (find(path.begin(), path.end(), l) != path.end())
                {
                    continue;
                }
                else
                {
                    copy = matrix;
                    for (int i = 0; i < n; i++)
                    {
                        copy[pre][i] = MAX;
                    }
                    for (int i = 0; i < n; i++)
                    {
                        copy[i][l] = MAX;
                    }
                    copy[start][l] = MAX;

                    int m = ReduceMatrix(copy, 0);
                    if (m < min)
                    {
                        min = m;
                        next = l;
                    }
                }
            }

            copy = matrix;

            for (int i = 0; i < n; i++)
            {
                copy[pre][i] = MAX;
            }
            for (int i = 0; i < n; i++)
            {
                copy[i][next] = MAX;
            }
            copy[start][next] = MAX;

            min = ReduceMatrix(copy, 1);
            MinCost += min;
            pre = next;
            path[index] = next;
            index++;
            min = MAX;
        }
    }

    void Print()
    {
        cout << "Minimum Path Cost: " << MinCost << endl
             << endl;

        cout << "The Travel Path is: " << path[0];
        for (int i = 1; i < n; i++)
        {
            cout << "->" << path[i];
        }
        cout << "->" << path[0];
    }
};

int main()
{
    int n;
    cout << "Enter no. of vertices: ";
    cin >> n;

    TSP a(n);
    a.read();
    a.tspsol();
    a.Print();

    return 0;
}