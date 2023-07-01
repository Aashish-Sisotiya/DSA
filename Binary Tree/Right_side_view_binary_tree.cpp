/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void bfs(TreeNode *root, vector<int> &ans)
    {
        if (!root)
            return;

        queue<TreeNode *> q;
        q.push(root);
        bool hasVisited = false;
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *frontNode = q.front();
                q.pop();
                if (!hasVisited)
                {
                    hasVisited = !hasVisited;
                    ans.push_back(frontNode->val);
                }
                if (frontNode->right)
                    q.push(frontNode->right);
                if (frontNode->left)
                    q.push(frontNode->left);
            }
            hasVisited = false;
        }
    }
    void dfs(TreeNode *root, vector<int> &ans, vector<int> &visited, int level)
    {
        if (root == NULL)
            return;

        if (!visited[level])
        {
            visited[level] = true;
            ans.push_back(root->val);
        }
        dfs(root->right, ans, visited, level + 1);
        dfs(root->left, ans, visited, level + 1);
    }

    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        // bfs(root,ans);
        vector<int> visited(101, false);
        dfs(root, ans, visited, 0);
        return ans;
    }
};