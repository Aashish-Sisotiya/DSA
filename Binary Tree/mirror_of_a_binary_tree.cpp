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
void invertBinaryTree(BinaryTreeNode<int> *root)
{
    if (!root)
        return;

    BinaryTreeNode<int> *temp;

    invertBinaryTree(root->left);
    invertBinaryTree(root->right);

    temp = root->left;
    root->left = root->right;
    root->right = temp;
}
void mirrorTree(BinaryTreeNode<int> *root)
{
    // Write your code here.
    invertBinaryTree(root);
}