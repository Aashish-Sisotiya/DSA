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
    int res = 0;
    int height(TreeNode *root)
    {
        if (!root)
            return 0;

        int lh = height(root->left);
        int rh = height(root->right);
        res = max(res, lh + rh);
        return max(lh, rh) + 1;
    }
    pair<int, int> heightDiameter(TreeNode *root)
    {
        if (!root)
        {
            return {0, 0};
        }

        pair<int, int> pairLeft = heightDiameter(root->left);
        pair<int, int> pairRight = heightDiameter(root->right);

        int lh = pairLeft.first;
        int rh = pairRight.first;
        int ld = pairLeft.second;
        int rd = pairRight.second;

        pair<int, int> result;
        result.first = max(lh, rh) + 1;
        result.second = max(lh + rh, max(ld, rd));
        return result;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int ht = height(root);
        pair<int, int> ans = heightDiameter(root);
        // return res;
        return ans.second;
    }
};