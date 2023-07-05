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
//Tc --> O(N) Sc--> O(N)
bool rootToNodePath(BinaryTreeNode<int> *root, int targetNode, vector<int> &ans)
{
    if (!root)
        return false;
    if (root->data == targetNode)
    {
        ans.push_back(root->data);
        return true;
    }
    ans.push_back(root->data);
    if (rootToNodePath(root->left, targetNode, ans) || rootToNodePath(root->right, targetNode, ans))
    {
        return true;
    }

    ans.pop_back();
    return false;
}

int findKthAncestor(BinaryTreeNode<int> *root, int targetNodeVal, int k)
{
    // Write your code here.
    vector<int> ans;
    rootToNodePath(root, targetNodeVal, ans);
    if (k >= ans.size())
        return -1;

    return ans[ans.size() - k - 1];
}

 //! Approach 2   Tc ---> O(N)  Sc  ---> O(N)  use level order traversal and store the first ancestor of every node it into the array and then traverse the array 




