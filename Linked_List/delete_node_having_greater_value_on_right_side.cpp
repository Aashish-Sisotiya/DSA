//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
public:
    vector<int> nextLargerNodes(Node *head)
    {
        if (head == NULL)
            return {};
        vector<int> vec;
        stack<int> st;
        Node *temp = head;
        while (temp)
        {
            vec.push_back(temp->data);
            temp = temp->next;
        }
        for (int i = vec.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= vec[i])
            {
                st.pop();
            }
            int elem = vec[i];
            vec[i] = st.empty() ? 0 : st.top();
            st.push(elem);
        }
        return vec;
    }
    //!  Tc --> O( N )   Sc ---> O(N) for array of next greater element 
    Node *compute(Node *head)
    {
        // your code goes here
        if (head == NULL)
            return head;
        vector<int> vec = nextLargerNodes(head);
        Node *dummy = new Node(-1);
        Node *temp = dummy, *curr = head;
        int i = 0;

        while (curr)
        {
            if (vec[i] == 0)
            {
                temp->next = curr;
                temp = temp->next;
            }
            curr = curr->next;
            i++;
        }
        return dummy->next;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int K;
        cin >> K;
        struct Node *head = NULL;
        struct Node *temp = head;

        for (int i = 0; i < K; i++)
        {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout << endl;
    }
}

// } Driver Code Ends

//! Tc ---> O( N ) Sc  --> O(1) 
//! first reverse the linked list and take a variable maxNode as head and it will keep track of the max value till any node , then perform operation on any node accourdingly. 

class Solution
{
    public:
    Node *compute(Node *head)
    {
        // First reversed the linked list
    
        Node *cur = head;
        Node *prev = NULL;
        Node *next;
    
        while(cur!=NULL)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
    
        head = prev;
    
        // Link list is reversed till here
    
        // Computing and deleting the nodes which have larger nodes
        // on the left
    
        Node *current = head;
    
        Node *maxNode = head;
        Node *temp;
    
         while (current != NULL && current->next != NULL)
         {
             if(current->next->data < maxNode->data)
             {
                 temp = current->next;
                 current->next = temp->next;
                 free(temp);
             }
             else
             {
                 current = current->next;
                 maxNode= current;
             }
         }
         
         // reversing list again to get required result :-
         
         cur = head;
         prev = NULL;
         next;
         while(cur!=NULL)
         {
             next = cur->next;
             cur->next = prev;
             prev = cur;
             cur = next;
         }
    
         head = prev;
         
         // head of list can be returned now
    
        return head;
    
    }
};