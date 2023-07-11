//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>, greater<pair<int, int>>>
            pq;

        vector<int> vis(V, 0);
        // {wt, node}
        pq.push({0, 0});
        int sum = 0;
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;

            if (vis[node] == 1)
                continue;
            // add it to the mst
            vis[node] = 1;
            sum += wt;
            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int edW = it[1];
                if (!vis[adjNode])
                {
                    pq.push({edW, adjNode});
                }
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends

#include <bits/stdc++.h>

vector<pair<pair<int, int>, int>>
calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    unordered_map<int, list<pair<int, int>>> adj;

    for (auto it : g)
    {
        int u = it.first.first;
        int v = it.first.second;
        int wt = it.second;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<int> key(n + 1);
    vector<int> parent(n + 1);
    vector<bool> mst(n + 1);

    for (int i = 0; i <= n; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }
    key[1] = 0;
    parent[1] = -1;

    for (int i = 1; i <= n; i++)
    {
        int mini = INT_MAX, u;
        for (int v = 1; v <= n; v++)
        {
            if (mst[v] == false && key[v] <= mini)
            { // find the minimum key/ edgeWt from the key array
                mini = key[v];
                u = v;
            }
        }
        mst[u] = true; // add to mst

        for (auto it : adj[u])
        {
            int adjNode = it.first;
            int edgeWt = it.second;
            if (mst[adjNode] == false && edgeWt < key[adjNode])
            {
                key[adjNode] = edgeWt;
                parent[adjNode] = u;
            }
        }

        vector<pair<pair<int, int>, int>> result;
        for (int i = 2; i <= n; i++)
        { // starting from 2 because parent[1] is -1;
            result.push_back({{i, parent[i]}, key[i]});
        }
        return result;
    }
}
