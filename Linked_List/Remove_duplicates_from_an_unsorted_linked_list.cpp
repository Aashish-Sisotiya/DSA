//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution
{
public:
    // Function to remove duplicates from unsorted linked list.
    Node *removeDuplicates(Node *head)
    {
        // your code goes here
        unordered_map<int, int> map;
        struct Node *temp = head;

        while (temp)
        {
            map[temp->data]++;
            temp = temp->next;
        }
        struct Node *dummy = new Node(-1);
        dummy->next = head;

        struct Node *prev, *curr = head;
        prev = dummy;

        while (curr)
        {
            if (map.find(curr->data) != map.end())
            {
                prev = curr;
                if (map[curr->data] > 1)
                {
                    map.erase(curr->data);
                }
            }
            else
            {
                prev->next = curr->next;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};

//{ Driver Code Starts.

int main()
{
    // your code goes here
    int T;
    cin >> T;

    while (T--)
    {
        int K;
        cin >> K;
        struct Node *head = NULL;
        struct Node *temp = head;

        for (int i = 0; i < K; i++)
        {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        Node *result = ob.removeDuplicates(head);
        print(result);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends