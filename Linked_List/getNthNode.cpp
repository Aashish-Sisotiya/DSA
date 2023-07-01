//{ Driver Code Starts
// Initial Template for C++
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
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

/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node *head, int n);

/* Driver program to test above function*/

// } Driver Code Ends
/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

// Function to find the data of nth node from the end of a linked list.
class Solution
{
public:
    int lengthOfLL(Node *head)
    {
        if (head == NULL)
            return 0;
        int len = 0;
        Node *temp = head;
        while (temp)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }
    int getNthFromLast(Node *head, int n)
    {
        // Your code here
        if (head == NULL)
            return -1;
        int length = lengthOfLL(head);
        if (n > length)
            return -1;
        if (length == n)
            return head->data;
        int nodeToFind = length - n + 1; 
        Node *temp = head;
        while (--nodeToFind)
        {
            temp = temp->next;
        }
        return temp->data;
    }
};

//{ Driver Code Starts.

int main()
{
    int T, i, n, l, k;

    cin >> T;

    while (T--)
    {
        struct Node *head = NULL, *tail = NULL;

        cin >> n >> k;
        int firstdata;
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        Solution obj;
        cout << obj.getNthFromLast(head, k) << endl;
    }
    return 0;
}
// } Driver Code Ends