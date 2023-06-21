class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node(int val)
    {
        this->val = val;
        prev = nullptr;
        next = nullptr;
    }
};
class MyStack
{
    Node *head = nullptr;
    Node *mid = nullptr;
    int size = 0;

public:
    void push(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
        {
            head = temp;
            mid = temp;
            size++;
        }
        head->next = temp;
        temp->prev = head;

        head = head->next;

        if (size % 2 == 1)
        {
            mid = mid->next;
        }
        size++;
    }
    int pop()
    {
        int data = 0;
        if (size != 0)
        {
            Node *toDelete = head;
            int data = toDelete->val;

            if (size == 1)
            {
                head = nullptr;
                mid == nullptr;
            }
            else
            {
                head = head->prev;
                head->next = nullptr;
            }
            delete toDelete;
            size--;
        }
        return data;
    }

    int findMiddle()
    {
        if (size == 0)
        {
            return -1;
        }
        return mid->val;
    }
    int deleteMiddle()
    {
        if (size != 0)
        {
            Node *toDelete = mid;
            if (size == 1)
            {
                head = nullptr;
                mid = nullptr;
            }
            else if (size == 2)
            {
                head = head->prev;
                mid = mid->prev;
                head->next = nullptr;
            }
            else
            {
                mid->next->prev = mid->prev;
                mid->prev->next = mid->next;
                if (size % 2 == 0)
                {
                    mid = mid->prev;
                }
                else
                {
                    mid = mid->next;
                }
            }
            delete toDelete;
            size--;
        }
    }
};