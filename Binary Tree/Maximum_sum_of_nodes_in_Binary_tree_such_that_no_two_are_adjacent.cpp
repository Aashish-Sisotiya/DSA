#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeTreeNode<int>(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int sumOfGrandChildren(TreeNode<int> *node,
                       map<TreeNode<int> *, int> &mp);
int getMaxSumUtil(TreeNode<int> *node, map<TreeNode<int> *, int> &mp);

int sumOfGrandChildren(TreeNode<int> *node,
                       map<TreeNode<int> *, int> &mp)
{
    int sum = 0;

    if (node->left)
        sum += getMaxSumUtil(node->left->left, mp) + getMaxSumUtil(node->left->right, mp);
    if (node->right)
        sum += getMaxSumUtil(node->right->left, mp) + getMaxSumUtil(node->right->right, mp);

    return mp[node] = sum;
}

int getMaxSumUtil(TreeNode<int> *node, map<TreeNode<int> *, int> &mp)
{
    if (node == NULL)
        return 0;

    if (mp.find(node) != mp.end())
        return mp[node];

    int incl = node->data + sumOfGrandChildren(node, mp);

    int excl = getMaxSumUtil(node->left, mp) + getMaxSumUtil(node->right, mp);

    mp[node] = max(incl, excl);

    return mp[node];
}
int maximumSumOfNodes(TreeNode<int> *root)
{
    //    Write your code here
    if (root == NULL)
        return 0;
    map<TreeNode<int> *, int> mp;
    return getMaxSumUtil(root, mp);
}