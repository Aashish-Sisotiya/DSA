#include <bits/stdc++.h>
/*********************************************************

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

************************************************************/
// https://www.prepbytes.com/blog/linked-list/reverse-a-doubly-linked-list-in-groups-of-given-size/
Node *reverseDLL(Node *head)
{
    // Your code here
    if (head == NULL && head->next == NULL)
        return head;
    Node *curr = head;

    while (curr->next)
    {
        curr = curr->next;
    }
    head = curr;
    curr->next = curr->prev;
    curr->prev = NULL;
    curr = curr->next;
    while (curr->prev)
    {
        Node *temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        curr = curr->next;
    }
    curr->prev = curr->next;
    curr->next = NULL;
    return head;
}
Node *reverseDLLInGroups(Node *head, int k)
{
    // Write your code here.
    if (head == NULL || head->next == NULL)
        return head;
    if (k == 1)
        return head;

    int inc = k - 1;
    Node *start = head, *end = head;
    while (inc)
    {
        inc--;
        end = end->next;
        if (end == NULL)
        {
            return reverseDLL(start);
        }
    }

    Node *temp = end->next;
    temp->prev = NULL;
    end->next = NULL;
    Node *newHead = reverseDLLInGroups(temp, k);

    end = reverseDLL(start);
    end->prev = NULL;

    start->next = newHead;
    newHead->prev = start;

    return end;
}
