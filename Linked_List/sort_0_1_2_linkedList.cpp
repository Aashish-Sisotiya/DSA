//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;

// } Driver Code Ends
/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
public:
    void sortZeroOneTwo(vector<int> &nums)
    {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
    // Function to sort a linked list of 0s, 1s and 2s.
    Node *segregate(Node *head)
    {

        // Add code here
        if (head == NULL || head->next == NULL)
            return head;
        // vector<int> ans;

        // Node* temp=head;
        // while(temp){
        //     ans.push_back(temp->data);
        //     temp=temp->next;
        // }
        // sortZeroOneTwo(ans);
        // Node* dummyNode=new Node(-1);
        // Node* temp1=dummyNode;
        // for(int i=0;i<ans.size();i++){
        //     Node* node=new Node(ans[i]);
        //     temp1->next=node;
        //     temp1=temp1->next;
        // }
        // return dummyNode->next;

        Node *zeroLL = new Node(0);
        Node *oneLL = new Node(0);
        Node *twoLL = new Node(0);

        Node *zero = zeroLL, *one = oneLL, *two = twoLL;

        Node *curr = head;
        while (curr)
        {
            if (curr->data == 0)
            {
                zero->next = curr;
                zero = zero->next;
            }
            else if (curr->data == 1)
            {
                one->next = curr;
                one = one->next;
            }
            else
            {
                two->next = curr;
                two = two->next;
            }
            curr = curr->next;
        }

        zero->next = (oneLL->next) ? (oneLL->next) : (twoLL->next);
        one->next = twoLL->next;
        two->next = NULL;

        head = zeroLL->next;
        return head;
    }
};

//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1)
{
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);

        if (i == 0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main()
{

    int n;

    int t;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends