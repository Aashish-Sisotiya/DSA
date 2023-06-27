//{ Driver Code Starts
// Initial template for C++

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

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data;
        node = node->next;
    }
    cout << "\n";
}

// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
    Node *reverse(struct Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        struct Node *prev = NULL, *curr = head, *next = head->next;
        while (curr)
        {
            curr->next = prev;
            prev = curr;
            curr = next;
            if (next)
                next = next->next;
        }
        return prev;
    }
    Node *addOne(Node *head)
    {
        // Your Code here
        // return head of list after adding one
        if (head == NULL)
            return head;
        struct Node *temp = reverse(head);
        struct Node *curr = temp;
        int carry = 0;
        while (curr)
        {
            if (curr->data != 9)
            {
                if (carry)
                {
                    curr->data = curr->data + carry;
                    carry = 0;
                    break;
                }
                curr->data = curr->data + 1;
                break;
            }
            else
            {
                curr->data = 0;
                carry = 1;
                if (curr->next == NULL && carry == 1)
                {
                    break;
                }
            }
            curr = curr->next;
        }
        if (carry)
        {
            curr->next = new Node(1);
            curr->next->next = NULL;
        }
        temp = reverse(temp);
        return temp;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Node *head = new Node(s[0] - '0');
        Node *tail = head;
        for (int i = 1; i < s.size(); i++)
        {
            tail->next = new Node(s[i] - '0');
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends