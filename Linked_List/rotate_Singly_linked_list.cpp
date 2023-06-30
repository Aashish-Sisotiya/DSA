class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
            return head;

        int len = 1;
        ListNode *tail = head;
        while (tail->next)
        {
            len++;
            tail = tail->next;
        }
        tail->next = head;
        k %= len;
        int newHeadIndex = (len - k) % len;
        for (int i = 0; i < newHeadIndex; i++)
        {
            tail = tail->next;
        }
        head = tail->next;
        tail->next = NULL;
        return head;
    }
};

 1 2 3 4 5 6 7 8 9
 7 8 9 1 2 3 4 5 6