#include <bits/stdc++.h>
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node *prev;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
                this->prev = NULL;
            }
        };

*****************************************************************/
struct compare
{
    bool operator()(Node *node1, Node *node2)
    {
        return node1->data > node2->data;
    }
};

Node *sortedDll(Node *head, int k)
{
    // Write your code here
    // can be done using inserting sort in O( N*K ) time complexity;
    // Tc  ---> O(K) + O( M(log(k)))  M =N-K

    if (head == NULL || head->next == NULL)
        return head;
    priority_queue<Node *, vector<Node *>, compare> pq;

    Node *curr = head;
    for (int i = 0; i <= k && curr != NULL; i++)
    {
        pq.push(curr);
        curr = curr->next;
    }
    Node *newHead = NULL, *last;
    while (!pq.empty())
    {
        if (newHead == NULL)
        {
            newHead = pq.top();
            newHead->prev = NULL;
            last = newHead;
        }
        else
        {
            last->next = pq.top();
            pq.top()->prev = last;
            last = pq.top();
        }
        pq.pop();
        if (curr)
        {
            pq.push(curr);
            curr = curr->next;
        }
    }
    last->next = NULL;
    return newHead;
}