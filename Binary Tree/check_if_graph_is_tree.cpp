#include <bits/stdc++.h>
bool dfs(int node, vector<bool> &visited, vector<int> adj[], int par)
{
    visited[node] = true;

    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            if (dfs(it, visited, adj, node))
            {
                return true;
            }
        }
        else
        {
            if (par != it)
            {
                return true;
            }
        }
    }
    return false;
}
bool isGraphTree(int n, vector<vector<int>> &edgeList)
{
    // Write your code here
    // Tc -- > O(V+2*e)
    // Sc  ---->O(V+2*e) + O(V) for visited array
    vector<int> adj[n];
    for (auto it : edgeList)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<bool> visited(n, false);
    if (dfs(0, visited, adj, -1))
        return false;

    for (auto it : visited)
    {
        if (!it)
            return false;
    }

    return true;
}