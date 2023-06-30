vector<pair<int, int>> findPairs(Node *head, int k)
{
    // Write your code here.
    vector<pair<int, int>> ans;
    Node *ptr1 = head, *ptr2 = head;
    /*  // Tc --> O( N^2 )
    while(ptr1){
        ptr2=ptr1->next;
        while(ptr2){
             if(ptr1->data+ptr2->data==k){
                 ans.push_back({ptr1->data,ptr2->data});
             }
             ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    return ans;
    */
   //Tc ---> O ( N )
    while (ptr2->next)
    {
        ptr2 = ptr2->next;
    }

    while (ptr1->data < ptr2->data)
    {
        if (ptr1->data + ptr2->data == k)
        {
            ans.push_back({ptr1->data, ptr2->data});
            ptr1 = ptr1->next;
            ptr2 = ptr2->prev;
        }
        else if (ptr1->data + ptr2->data < k)
        {
            ptr1 = ptr1->next;
        }
        else
        {
            ptr2 = ptr2->prev;
        }
    }
    return ans;
}
