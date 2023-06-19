class MyStack {
public:
    // queue<int> q1;
    // queue<int> q2;
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        //using 2 queues
        // q2.push(x);
        // while(!q1.empty()){
        //     q2.push(q1.front());
        //     q1.pop();
        // }
        // swap(q1,q2);

        //using single queue
         
        q.push(x);
        int size=q.size();
        for(int i=0;i<size-1;i++){
            int temp=q.front();
            q.pop();
            q.push(temp);
        }
        
    }
    
    int pop() {
        // int front=q1.front();
        // q1.pop();
        // return front;

         int front=q.front();
        q.pop();
        return front;
    }
    
    int top() {
        // return q1.front();

        return q.front();
    }
    
    bool empty() {
        // return q1.empty();

        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */