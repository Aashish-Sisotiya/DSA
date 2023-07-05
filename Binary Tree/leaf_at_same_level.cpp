//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
/* The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution
{
public:
    /*You are required to complete this method*/
    int level = -1;
    bool sameLeafLevel(Node *root, int leafLevel)
    {
        if (root == NULL)
            return true;
        if (root->left == NULL and root->right == NULL)
        {
            if (level == -1)
            {
                level = leafLevel;
                return true;
            }
            return level == leafLevel;
        }
        return sameLeafLevel(root->left, leafLevel + 1) and sameLeafLevel(root->right, leafLevel + 1);
    }

    bool sameLeafLevelIterative(Node *root)
    {
        if (root == NULL)
            return true;

        int flag = 0;
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                Node *front = q.front();
                q.pop();
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
                if (front->left == NULL and front->right == NULL)
                {
                    flag = 1;
                }
            }

            // check if the queue has some elements  or not , if queue has more eements and flag ==1 then it means we have reached a leaf node and still there are some elemnts in the queue so the nodes in the queue has some leaf node of some greater level, so return false
            if (flag && !q.empty())
            {
                return 0;
            }
        }
        return 1;
    }
    //! another approach is to find the maxDist(same as height) and minDist(minor change in maxHeight of binary tree function, if node==NULL return INT_MAX return min(leftHeight,rightHeight)+1) if both are equal then leaf are at same level otherwise ate different level
    bool check(Node *root)
    {
        // Your code here
        //  can be done both using bfs and dfa

        if (root == NULL)
            return true;
        int leafLevel = 0;
        // return sameLeafLevel(root,leafLevel);
        return sameLeafLevelIterative(root);
    }
};

//{ Driver Code Starts.
// Driver program to test size function
int main()
{
    int t;
    cin >> t;
    getchar();
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *head = buildTree(s);
        Solution obj;
        cout << obj.check(head) << endl;
    }
    return 0;
}

// } Driver Code Ends