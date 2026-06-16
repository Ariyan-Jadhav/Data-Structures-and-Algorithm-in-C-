#include <bits/stdc++.h>
using namespace std;

class DisJointSet
{
    vector<int> rank, parent, size;

public:
    DisJointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUpar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ultimate_u = findUpar(u);
        int ultimate_v = findUpar(v);

        if (ultimate_u == ultimate_v)
            return;
        if (rank[ultimate_u] < rank[ultimate_v])
            parent[ultimate_u] = ultimate_v;
        else if (rank[ultimate_u] > rank[ultimate_v])
            parent[ultimate_v] = ultimate_u;
        else
        {
            parent[ultimate_u] = ultimate_v;
            rank[ultimate_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ultimate_u = findUpar(u);
        int ultimate_v = findUpar(v);

        if (ultimate_u == ultimate_v)
            return;
        if (size[ultimate_u] > size[ultimate_v])
        {
            parent[ultimate_u] = ultimate_v;
            size[ultimate_u] += size[ultimate_v];
        }
        else if (size[ultimate_u] < size[ultimate_v])
        {
            parent[ultimate_v] = ultimate_u;
            size[ultimate_v] += size[ultimate_u];
        }
        else
        {
            parent[ultimate_u] = ultimate_v;
            size[ultimate_u] += size[ultimate_v];
        }
    }
};

int main()
{
    DisJointSet ds(7);

    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    cout << ds.findUpar(3);
    ds.unionByRank(3, 7);
    cout << ds.findUpar(3);

    return 0;
}