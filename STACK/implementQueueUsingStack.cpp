class MyQueue {
public:
    // stack<int> s1;
    // stack<int> s2;

    stack<int> input;
    stack<int> output;
    MyQueue() {
        
    }
    
    void push(int x) {
        // using 2 stack
        // while(!s1.empty()){
        //     int top=s1.top();
        //     s1.pop();
        //     s2.push(top);
        // }
        // s2.push(x);
        // while(!s2.empty()){
        //     s1.push(s2.top());
        //     s2.pop();
        // }

        //using 1 stack
        input.push(x);
         
    }
    
    int pop() {
        // int top=s1.top();
        // s1.pop();
        // return top;
        int x=peek();
        output.pop();
       return x;       
    }
    
    int peek() {
        // return s1.top();

        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
         
        return output.top();
    }
    
    bool empty() {
        // return s1.empty();

        return (input.empty() && output.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */