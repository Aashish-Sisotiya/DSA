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
    void zigzagTraversal(TreeNode *root, vector<vector<int>> &ans)
    {
        if (!root)
            return;

        queue<TreeNode *> q;
        q.push(root);
        int flag = 0;
        while (!q.empty())
        {
            int n = q.size();
            vector<int> temp;
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                temp.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            if (flag == 0)
            {
                flag = 1;
            }
            else
            {
                reverse(temp.begin(), temp.end());
                flag = 0;
            }
            ans.push_back(temp);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;

        zigzagTraversal(root, ans);
        return ans;
    }
};