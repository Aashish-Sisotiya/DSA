/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    void reverse(ListNode *s, ListNode *e)
    {
        ListNode *p = NULL, *c = s, *n = s->next;
        while (p != e)
        {
            c->next = p;
            p = c;
            c = n;
            if (n != NULL)
                n = n->next;
        }
    }
    int length(ListNode *head)
    {
        int len = 0;
        while (head)
        {
            head = head->next;
            len++;
        }
        return len;
    }
    ListNode *dummy = new ListNode(0), *prev = dummy;
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        //     if(head==NULL || head->next==NULL||k==1){
        //         return head;
        //     }
        //     ListNode * s=head,*e=head;
        //     int inc=k-1;
        //     while(inc--){
        //         e=e->next;
        //         if(e==NULL)return head;
        //     }

        //   ListNode * nxtHead=  reverseKGroup(e->next,k);
        //      reverse(s,e);
        //     s->next=nxtHead;
        //     return e;

        dummy->next = head;
        int len = length(head);
        for (int i = 0; i < len / k; i++)
        {
            for (int j = 1; j < k; j++)
            {
                ListNode *temp = prev->next;
                prev->next = head->next;
                head->next = head->next->next;
                prev->next->next = temp;
            }
            prev = head;
            head = head->next;
        }
        return dummy->next;
    }
};