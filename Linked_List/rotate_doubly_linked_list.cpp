#include <bits/stdc++.h>
/****************************************************

    Following is the class structure of the DLLNode class:

    class DLLNode {
    public:
    int data;
    Node *next;

    DLLNode(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
}

*****************************************************/

DLLNode *rotateDLL(DLLNode *head, int k)
{
    // Write your code here.
    if (!head)
        return head;

    int len = 1;
    DLLNode *tail = head;
    while (tail->next)
    {
        len++;
        tail = tail->next;
    }
    tail->next = head;
    head->prev = tail;
    k %= len;
    k = len - k;    //rotating k node in counter clockwise direction means rotating len - k time in clockwise direaction
    int newHeadIndex = (len - k) % len;
    for (int i = 0; i < newHeadIndex; i++)
    {
        tail = tail->next;
    }
    head = tail->next;
    head->prev = NULL;
    tail->next = NULL;
    return head;
}