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
    // Tc ---> O(N^2) because for we have N subtrees anf for hashing N subtree take O(N) time .
    // string serialiseTree(TreeNode* root,unordered_map<string,int> & subtrees,vector<TreeNode*>&duplicate){
    //     if(root==NULL)return "$";

    //     string leftSubtree=serialiseTree(root->left,subtrees,duplicate);
    //     string rightSubtree=serialiseTree(root->right,subtrees,duplicate);

    //     string s=leftSubtree+','+rightSubtree+','+to_string(root->val);

    //     if(subtrees[s]==1){
    //         duplicate.push_back(root);
    //     }
    //     subtrees[s]++;
    //     return s;
    // }

    //! Tc --> O(N)
    int serialiseTree(TreeNode *root, unordered_map<string, int> &tripletToId, unordered_map<int, int> &cnt, vector<TreeNode *> &duplicate)
    {
        if (root == NULL)
            return 0;

        string triplet = to_string(serialiseTree(root->left, tripletToId, cnt, duplicate)) + "," + to_string(root->val) + "," + to_string(serialiseTree(root->right, tripletToId, cnt, duplicate));

        if (!tripletToId.count(triplet))
        {
            tripletToId[triplet] = tripletToId.size() + 1;
        }
        int id = tripletToId[triplet];
        cnt[id]++;
        if (cnt[id] == 2)
        {
            duplicate.push_back(root);
        }
        return id;
    }

    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        vector<TreeNode *> duplicate;
        // unordered_map<string,int> subtrees;
        unordered_map<int, int> cnt;
        unordered_map<string, int> tripletToId;

        // string s=serialiseTree(root,subtrees,duplicate);
        int s = serialiseTree(root, tripletToId, cnt, duplicate);
        return duplicate;
    }
};