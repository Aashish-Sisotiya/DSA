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
    //! Tc ----> O(N*h) h=log(N)  but it can be N in worst cast
    //! T(N) = k*n + 2*T(N/2)
    //! Sc  ---> O(N) height of stack space which can be N in worst case

    // create a root node , then for its right or left child  call recursively and pass parameters accourdingly
    int findIndex(vector<int> in, int n, int value)
    {
        int idx = 0;
        for (int i = 0; i < n; i++)
        {
            if (in[i] == value)
            {
                idx = i;
            }
        }
        return idx;
    }
    TreeNode *constructTree(vector<int> in, vector<int> pre, int n, int preSt, int preEnd, int inSt, int inEnd)
    {

        if (preSt > preEnd || inSt > inEnd)
        {
            return NULL;
        }

        TreeNode *root = new TreeNode(pre[preSt]);
        int value = pre[preSt];
        int index = findIndex(in, n, value);
        int len = index - inSt;

        int leftPreSt = preSt + 1;
        int leftPreEnd = leftPreSt + len - 1;

        int rightPreSt = leftPreEnd + 1;
        int rightPreEnd = preEnd;

        int rightInSt = index + 1;
        int rightInEnd = inEnd;

        int leftInSt = inSt;
        int leftInEnd = index - 1;

        root->left = constructTree(in, pre, n, leftPreSt, leftPreEnd, leftInSt, leftInEnd);
        root->right = constructTree(in, pre, n, rightPreSt, rightPreEnd, rightInSt, rightInEnd);

        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = preorder.size();
        return constructTree(inorder, preorder, n, 0, n - 1, 0, n - 1);
    }
};

//! another approach  instead of passing preorder array parameter , keep a perIndex variable which will be used in every recursive call 
//! Tc ---> O(N) because we have used map to store the index of inorder element 

struct Node *buildTree(char in[], char pre[], int inStrt,
                       int inEnd, unordered_map<char, int> &mp)
{
    static int preIndex = 0;

    if (inStrt > inEnd)
        return NULL;

    /* Pick current node from Preorder traversal using preIndex
    and increment preIndex */
    char curr = pre[preIndex++];
    struct Node *tNode = newNode(curr);

    /* If this node has no children then return */
    if (inStrt == inEnd)
        return tNode;

    /* Else find the index of this node in Inorder traversal */
    int inIndex = mp[curr];

    /* Using index in Inorder traversal, construct left and
    right subtress */
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1, mp);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd, mp);

    return tNode;
}

// This function mainly creates an unordered_map, then
// calls buildTree()
struct Node *buldTreeWrap(char in[], char pre[], int len)
{
    // Store indexes of all items so that we
    // we can quickly find later
    unordered_map<char, int> mp;
    for (int i = 0; i < len; i++)
        mp[in[i]] = i;

    return buildTree(in, pre, 0, len - 1, mp);
}