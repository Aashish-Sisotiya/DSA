class MinStack {
public:
    stack<pair<int,int>> st; 
    // stack<int> st;
    int mini;
    MinStack() { 
        mini=INT_MAX;
    }
    
    void push(int val) {
        int mini;
        if(st.empty()){
             mini=val; 
        }
        else{
            mini=min(st.top().second,val);
        }
        st.push({val,mini});      
       
    }
    
    void pop() {
         st.pop();
         
    }
    
    int top() {
       return st.top().first;
    // return st.top();
    }
    
    int getMin() {
        return st.top().second;
        // return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class MinStack {
public:
    stack<long long> st;
    long long mini;
    MinStack() {
        mini=INT_MAX;
    }
    
    void push(int val) {
        long long value=val;
        if(st.empty()){
            mini=value;
            st.push(value); 
        }
        else{
            if(val<mini){
                st.push(2 * value * 1LL - mini); 
                mini=val;
            }
            else {
                st.push(value); 
            }
        }
    }
    
    void pop() {
        if(st.empty())return;

        long long elem=st.top(); 
        st.pop();
        if(elem < mini){
            mini=2*mini - elem; 
        } 
    }
    
    int top() {
         if(st.empty())return -1;
         long long elem=st.top();

         if(elem < mini)return mini;
         return elem;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */