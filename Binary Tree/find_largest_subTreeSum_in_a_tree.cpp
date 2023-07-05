#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int findLargestSubtreeSumUtil(BinaryTreeNode<int> *root, int &ans)
{
    if (root == NULL)
        return 0;
    int currSum = root->data + findLargestSubtreeSumUtil(root->left, ans) + findLargestSubtreeSumUtil(root->right, ans);

    ans = max(ans, currSum);

    return currSum;
}

long long maxSubtreeSum(BinaryTreeNode<int> *root)
{
    // Write your code here.
    if (root == NULL)
        return 0;

    int ans = INT_MIN;
    // Tc -- > O(N)
    // one approach is  to find the preorder of the tree and store it in a vector and then traverse the preorder vector and then do a preorder traversal from vector[i] for every node in the tree , Tc --> O(N^2);

    findLargestSubtreeSumUtil(root, ans);

    return ans;
}
