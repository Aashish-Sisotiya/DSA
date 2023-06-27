//{ Driver Code Starts
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

int intersectPoint(struct Node *head1, struct Node *head2);

vector<int> take(int n)
{
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
        cin >> ans[i];
    return ans;
}

Node *inputList(int size, vector<int> v)
{
    if (size == 0)
        return NULL;

    int val = v[0];

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        val = v[i + 1];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

/* Driver program to test above function*/
int main()
{
    srand(time(0));
    int T, n1, n2, n3;

    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3;

        int p = rand() % 3;

        vector<int> v1 = take(n1);
        vector<int> v2 = take(n2);
        vector<int> v3 = take(n3);

        Node *head1 = NULL;
        Node *head2 = NULL;
        Node *common = NULL;

        if (p == 0)
        {
            common = inputList(n3, v3);
            head1 = inputList(n1, v1);
            head2 = inputList(n2, v2);
        }
        else if (p == 1)
        {

            head1 = inputList(n1, v1);
            common = inputList(n3, v3);
            head2 = inputList(n2, v2);
        }
        else
        {

            head1 = inputList(n1, v1);
            head2 = inputList(n2, v2);
            common = inputList(n3, v3);
        }

        Node *temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends

/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

// Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node *headA, Node *headB)
{
    // Your Code Here

    //! APPROACH 1 Tc --> O(M*N)  Sc-->O(1)  take first pointer of linked list 1 and compare it with all the elements of the other linked list
    //!  APPROACH 2 Tc ---> (M+N) Sc---> O(1) use a hashmap to traverse the first linked list and then travese the second linked list if u encounter a node wthich is there in the hashmap it means it is the intersection of linked list, return it

    //! APPROACH 3 Tc--> O(M+N) find the lenght of both the linked list and traverse the linked list which is of bigger lenght till abs(len2-len1)  and then start traversing both the linked list till end, smaller start traversing from the starting and the movement u reach a equal value return it

    //! APPROACH 4 use two pointer to traverse both the lined list if u reach a NULL value the point that pointer to the other's head  and continue traversing the linked list till last ot till u get a equal value
    ? ? if (headA == NULL || headB == NULL) return NULL;

    struct Node *temp1 = headA, *temp2 = headB;

    while (temp1 != temp2)
    {
        if (temp1 == NULL)
            temp1 = headB;
        else
            temp1 = temp1->next;
        if (temp2 == NULL)
            temp2 = headA;
        else
            temp2 = temp2->next;
    }
    return temp1 ? temp1->data : -1;
}
