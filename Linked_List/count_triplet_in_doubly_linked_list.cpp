 #include <bits/stdc++.h>
/***************************************

    Following is the Node class already written.

    class Node
    {
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int data)
        {
            next = NULL; prev=NULL;
            this->data = data;
        }

        ~Node()
        {
            if (next != NULL)
            {
                delete next;
            }
        }
    };

***************************************/
//! APPROACH 1  Tc  ---> O( N^3 ) use 3 nested loop to find the sum 
//! APPROACH 2  Tc  ---> O( N^2 ) Sc --> O( N ) use a hahsmap and fix the first element and then iterate fron first+1 elem to find pair 
//! APPROACH 3  Tc  ---> O( N^2 ) Sc --> O( 1 ) fix first element and then use two pointer approach to find the pairs in the linked list 
 

int findPairs(Node* first,Node* second,int value){
    int count=0;
    while(first && second && first!=second && second->next!=first){
        if(first->data+second->data==value){
            count++;
            first=first->next;
            second=second->prev;
        }
        else if(first->data+second->data<value){
            first=first->next;
        }
        else {
            second=second->prev;
        }
    }
    return count;
}

int countAllTripletSum(Node *head, int x)
{
    // Write your code here.
   if(head==NULL)return 0;
    int count=0;
   Node* curr=head,*first,*last=head;
   while(last->next){
       last=last->next;
   }
   while(curr){
       first=curr->next;
       count+=findPairs(first,last,x-curr->data);
       curr=curr->next;
   }
   return count;

}