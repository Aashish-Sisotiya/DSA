#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUltimateParent(int node)
    {
        if (node == parent[node]) // 1 -> 2 -> 3
        {
            return node; // it is the ultimate parent so we can return it directly as it is
        }
        return parent[node] = findUltimateParent(parent[node]); // path compression
    }
    void unionByRank(int u, int v)
    {
        int ult_par_u = findUltimateParent(u);
        int ult_par_v = findUltimateParent(v);
        if (ult_par_u == ult_par_v)
            return; // because they belong to same compontent

        if (rank[ult_par_u] < rank[ult_par_v])
        {
            parent[ult_par_u] = ult_par_v; // change the parent of smaller rank
        }
        else if (rank[ult_par_u] > rank[ult_par_v])
        {
            parent[ult_par_v] = ult_par_u;
        }
        else
        {
            parent[ult_par_v] = ult_par_u;
            rank[ult_par_u]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int ult_par_u = findUltimateParent(u);
        int ult_par_v = findUltimateParent(v);
        if (ult_par_u == ult_par_v)
            return; // because they belong to same compontent
        if (size[ult_par_u] < size[ult_par_v])
        {
            parent[ult_par_u] = ult_par_v;
            size[ult_par_v] += size[ult_par_u];
        }
        else
        {
            parent[ult_par_v] = ult_par_u;
            size[ult_par_u] += size[ult_par_v];
        }
    }
};

int main()
{
    DisjointSet dis(7);
    dis.unionByRank(1, 2);
    dis.unionByRank(2, 3);
    dis.unionByRank(4, 5);
    dis.unionByRank(6, 7);
    dis.unionByRank(5, 6);

    if (dis.findUltimateParent(3) == dis.findUltimateParent(7))
    {
        cout << "same";
    }
    else
    {
        cout << "not same";
    }
    dis.union(3, 7);
    if (dis.findUltimateParent(3) == dis.findUltimateParent(7))
    {
        cout << "same";
    }
    else
    {
        cout << "not same";
    }

    return 0;
}