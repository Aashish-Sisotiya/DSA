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

vector<int> leftView(struct Node *root);

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

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
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

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        vector<int> vec = leftView(root);
        for (int x : vec)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// Function to return a list containing elements of left view of the binary tree.
void bfs(Node *root, vector<int> &ans)
{
    if (!root)
        return;

    queue<Node *> q;
    q.push(root);
    bool hasVisited = false;
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *frontNode = q.front();
            q.pop();
            if (!hasVisited)
            {
                hasVisited = !hasVisited;
                ans.push_back(frontNode->data);
            }
            if (frontNode->left)
                q.push(frontNode->left);
            if (frontNode->right)
                q.push(frontNode->right);
        }
        hasVisited = false;
    }
}
void dfs(Node *root, vector<int> &ans, vector<int> &visited, int level)
{
    if (root == NULL)
        return;

    if (!visited[level])
    {
        visited[level] = true;
        ans.push_back(root->data);
    }
    dfs(root->left, ans, visited, level + 1);
    dfs(root->right, ans, visited, level + 1);
}

vector<int> leftView(Node *root)
{
    // Your code here
    // can be done both using bfs and dfs
    // BFS  use level order traversal and while store a vector temp in vector ans store the first element into the leftViewVector
    vector<int> ans;
    if (root == NULL)
        return ans;
    //   bfs(root,ans);
    vector<int> visited(101, false);
    dfs(root, ans, visited, 0);
    return ans;
}
