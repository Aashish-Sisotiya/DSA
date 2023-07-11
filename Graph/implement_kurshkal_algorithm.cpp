#include <bits/stdc++.h>

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
int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    /*
      Don't write main().
      Don't read input, it is passed as function argument.
      No need to print anything.
      Taking input and printing output is handled automatically.
    */
    vector<pair<int, pair<int, int>>> adj;
    int mstSum = 0;

    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        adj.push_back({wt, {u, v}});
    }

    sort(adj.begin(), adj.end());
    DisjointSet ds(n);
    for (auto it : adj)
    {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if (ds.findUltimateParent(u) != ds.findUltimateParent(v))
        {
            mstSum += wt;
            ds.unionByRank(u, v);
        }
    }

    return mstSum;
}