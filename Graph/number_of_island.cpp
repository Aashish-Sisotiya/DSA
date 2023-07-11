//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
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
class Solution
{
public:
    bool isValid(int adjRow, int adjCol, int n, int m)
    {
        return (adjRow >= 0 && adjRow < n && adjCol >= 0 && adjCol < m);
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        // code here
        DisjointSet ds(n * m);

        vector<vector<int>> visited(n, vector<int>(m, 0));
        int cnt = 0;
        vector<int> ans;

        for (auto it : operators)
        {
            int row = it[0];
            int col = it[1];
            // if already visited then no need to fo anything
            if (visited[row][col] == 1)
            {
                ans.push_back(cnt);
                continue;
            }
            visited[row][col] = 1;
            cnt++;

            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, -1, 0, 1};

            for (int i = 0; i < 4; i++)
            {
                int adjRow = row + delRow[i];
                int adjCol = col + delCol[i];

                if (isValid(adjRow, adjCol, n, m))
                {
                    if (visited[adjRow][adjCol] == 1)
                    {
                        int nodeNo = row * m + col;
                        int adjNodeNo = adjRow * m + adjCol;
                        if (ds.findUltimateParent(nodeNo) != ds.findUltimateParent(adjNodeNo))
                        {
                            cnt--;
                            ds.unionByRank(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> a;

        for (int i = 0; i < k; i++)
        {
            vector<int> temp;
            for (int j = 0; j < 2; j++)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.numOfIslands(n, m, a);

        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }
}

// } Driver Code Ends