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
    void levelOrderTraversal(TreeNode *root, vector<vector<int>> &ans)
    {
        if (root == NULL)
            return;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            vector<int> temp;
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                temp.push_back(node->val);
            }
            ans.push_back(temp);
        }
    }
    void dfs(TreeNode *root, vector<vector<int>> &ans, int depth)
    {
        if (!root)
            return;
        if (depth >= ans.size())
            ans.push_back({});

        ans[depth].push_back(root->val);
        dfs(root->left, ans, depth + 1);
        dfs(root->right, ans, depth + 1);
    }
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;

        //  levelOrderTraversal(root,ans);
        dfs(root, ans, 0);
        return ans;
    }
};