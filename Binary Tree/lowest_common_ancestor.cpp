/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return NULL;
        if (root == p || root == q)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if ((left != NULL && right != NULL))
        {
            return root;
        }
        else if (left != NULL && right == NULL)
        {
            return left;
        }
        else if (left == NULL && right != NULL)
        {
            return right;
        }
        else
        {
            return NULL;
        }
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<TreeNode *> nodeToRootPath(TreeNode *node, TreeNode *x)
    {
        if (node == NULL)
        {
            vector<TreeNode *> output;
            return output;
        }
        if (node->val == x->val)
        {
            vector<TreeNode *> output;
            output.push_back(node);
            return output;
        }
        vector<TreeNode *> leftOutput = nodeToRootPath(node->left, x);
        if (leftOutput.size() > 0)
        {
            leftOutput.push_back(node);
            return leftOutput;
        }
        vector<TreeNode *> rightOutput = nodeToRootPath(node->right, x);
        if (rightOutput.size() > 0)
        {
            rightOutput.push_back(node);
            return rightOutput;
        }
        vector<TreeNode *> blank;
        return blank;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        if (root == NULL)
            return root;
        vector<TreeNode *> vec1;
        vec1 = nodeToRootPath(root, p);
        vector<TreeNode *> vec2;
        vec2 = nodeToRootPath(root, q);

        int i = vec1.size() - 1;
        int j = vec2.size() - 1;
        TreeNode *ans;
        while (i >= 0 && j >= 0)
        {
            if (vec1[i]->val == vec2[j]->val)
            {
                ans = vec1[i];
                i--;
                j--;
            }
            else
            {
                break;
            }
        }

        return ans;
    }
};