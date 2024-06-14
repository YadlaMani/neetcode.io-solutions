class MinStack {
public:
    stack<int>st;//stack for general stack implementation
    vector<int>mm;//for keeping the minimum element upto that postion
    MinStack() {
        
    }
    
    void push(int val) {
         st.push(val);
        
        if(mm.empty() || val <= mm.back()) {//check if we have minimum element already or the current element is the minimum element and push if it's minimum
            mm.push_back(val);
        }
    }
    
    void pop() {
        if(st.empty()) return; //if the element we are about to remove is minimum remove that from the vector
        if(st.top() == mm.back()) {
            mm.pop_back();
        }
        st.pop();
        
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
         return mm.back();
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
