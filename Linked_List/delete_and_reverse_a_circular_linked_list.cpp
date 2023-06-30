void deleteNode(struct Node **head, int key)
{

// Your code goes here
    if(*head==NULL)return;
    if((*head)->data==key && (*head)->next==*head){   // head->data== data and it is the only  node in the circular linkde list
        free(*head);
        *head=NULL;
        return;
    }
    
    Node* last=*head,*temp;
    if((*head)->data==key){   // if the node to be deleted is the first node
        while(last->next!=*head){
            last=last->next;
        }
        last->next=(*head)->next;
        free(*head);
        *head=last->next;
        return;
    }
    while(last->next!=(*head) && last->next->data!=key){    // traverse the list till u get the key
        last=last->next;
    }
    if(last->next->data==key){
        temp=last->next;
        last->next=temp->next;
        free(temp);
    }

}

/* Function to reverse the linked list */
 void reverse(struct Node** head_ref)
{
if (*head_ref == NULL)
        return; 
    Node* prev = NULL;
    Node* current = *head_ref;
    Node* next;
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != (*head_ref)); 
    (*head_ref)->next = prev;
    *head_ref = prev;
    

}