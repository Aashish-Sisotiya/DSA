class Node
{
public:
    int key;
    int val;
    Node *next;
    Node *prev;

    Node(int key, int val)
    {
        this->key = key;
        this->val = val;
        next = prev = NULL;
    }
};
class LRUCache
{
public:
    unordered_map<int, Node *> map;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int cap;
    void deleteNode(Node *delNode)
    {
        Node *delNext = delNode->next;
        Node *delPrev = delNode->prev;

        delNext->prev = delPrev;
        delPrev->next = delNext;
    }
    void addNode(Node *newNode)
    {
        Node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        temp->prev = newNode;
        head->next = newNode;
    }

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (map.find(key) != map.end())
        {
            Node *resNode = map[key];
            int res = resNode->val;
            map.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            map[key] = head->next;

            return res;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (map.find(key) != map.end())
        {
            Node *existNode = map[key];
            map.erase(key);
            deleteNode(existNode);
        }
        if (map.size() == cap)
        {
            map.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node *node = new Node(key, value);
        addNode(node);
        map[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */