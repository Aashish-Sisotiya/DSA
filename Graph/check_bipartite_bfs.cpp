class Solution
{
public:
    bool checkBipartite(int start, vector<int> &colors, vector<int> adj[])
    {

        queue<int> q;
        q.push(start);

        colors[start] = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto it : adj[node])
            {
                if (colors[it] == -1)
                {
                    colors[it] = !colors[node];
                    q.push(it);
                }
                else if (colors[it] == colors[node])
                {
                    return false;
                }
            }
        }
        return true;
    }
    // ! Tc --> O(V)  + O(V + E)   Sc----> O(V) + O(V+E)
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();

        vector<int> adj[n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < graph[i].size(); j++)
            {
                adj[i].push_back(graph[i][j]);
            }
        }

        vector<int> colors(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (colors[i] == -1)
            {
                if (checkBipartite(i, colors, adj) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

bool isBipartiteDfs(int start, int color, vector<int> &colors, vector<int> adj[])
{

    colors[start] = color;

    for (auto it : adj[start])
    {
        if (colors[it] == -1)
        {
            if (isBipartiteDfs(it, 1 - color, colors, adj) == false)
            {
                return false;
            }
        }
        else if (colors[it] == color)
        {
            return false;
        }
    }
    return true;
}
bool isBipartite(int V, vector<int> adj[])
{
    // Code here
    vector<int> colors(V, -1);

    for (int i = 0; i < V; i++)
    {
        if (colors[i] == -1)
        {
            if (isBipartiteDfs(i, 0, colors, adj) == false)
            {
                return false;
            }
        }
    }
    return true;
}