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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;

        ListNode* prev=NULL ,*curr=head;
        while(curr){
            if(prev!=NULL && curr->val==prev->val){
                prev->next=curr->next;
                curr=curr->next;
                continue;
            }
            prev=curr;
            curr=curr->next;
        }
        return head;
    }
};