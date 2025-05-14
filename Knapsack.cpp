#include <iostream>
#include <vector>

using namespace std;

class node
{
public:
    vector<int> items;
    double u, l;

    node(int x)
    {
        items.resize(x, 1);
        u = l = 0;
    }
};

class knap
{
    int n, w;
    vector<int> profit, weight;

public:
    void read()
    {
        cout << "Enter the no. of items: ";
        cin >> n;

        cout << "Enter the weight capacity: ";
        cin >> w;

        profit.resize(n, 0);
        weight.resize(n, 0);

        cout << "Enter the profit and weight of each item: ";
        for (int i = 0; i < n; i++)
        {
            cin >> profit[i] >> weight[i];
        }
    }

    double upper(vector<int> &items)
    {
        double c = 0, W = 0;

        for (int i = 0; i < n; i++)
        {
            if (items[i] != 0)
            {
                if (W + weight[i] <= w)
                {
                    W += weight[i];
                    c += profit[i];
                    items[i] = 2;
                }
                else
                {
                    break;
                }
            }
        }

        return c;
    }

    double lower(vector<int> items)
    {
        int W = 0, d = 0;
        double c = 0;

        for (int i = 0; i < n; i++)
        {
            if (items[i] != 0)
            {
                if (W + weight[i] <= w)
                {
                    W += weight[i];
                    c += profit[i];
                }
                else
                {
                    d = w - W;
                    W += d;
                    c += (d / weight[i]) * profit[i];
                    break;
                }
            }
        }

        return c;
    }

    int total_weight(const vector<int> &items)
    {
        int total = 0;
        for (int i = 0; i < n; ++i)
        {
            if (items[i] == 2)
            {
                total += weight[i];
            }
        }
        return total;
    }

    void knapsack()
    {
        node root(n);
        node left(n);
        node right(n);

        root.u = upper(root.items);
        root.l = lower(root.items);

        for (int i = 0; i < n; i++)
        {
            left.items = root.items;
            right.items = root.items;

            right.items[i] = 0;

            left.u = upper(left.items);
            right.u = upper(right.items);
            left.l = lower(left.items);
            right.l = lower(right.items);

            int left_wt = total_weight(left.items);
            int right_wt = total_weight(right.items);

            if (left.l > right.l && left_wt <= w)
            {
                root = left;
            }
            else if (right.l > left.l && right_wt <= w)
            {
                root = right;
            }
            else
            {
                if (left.u >= right.u && left_wt <= w)
                {
                    root = left;
                }
                else if (right.u > left.u && right_wt <= w)
                {
                    root = right;
                }
            }
        }

        cout << "\nSelected items: ";
        int p = 0, m = 0;
        for (int i = 0; i < n; i++)
        {
            if (root.items[i] == 2)
            {
                cout << "Item " << i + 1 << " ";
                p += profit[i];
                m += weight[i];
            }
        }
        cout << "\nTotal Profit: " << p;
        cout << "\nTotal Weight: " << m << endl;
    }
};

int main()
{
    knap k;
    k.read();
    k.knapsack();
}