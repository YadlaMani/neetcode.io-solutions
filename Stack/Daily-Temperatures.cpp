class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        vector<int>ans(n,0);
        stack<int>st;
        for(int i=n-1;i>=0;i--){//traverse the arrays from reverse 
            //keep track of the hightest element at the front
            while(!st.empty()&&t[st.top()]<=t[i]){
                st.pop();
            }//if there is a element at the front higher than the currnet element minus the index
            if(!st.empty()) ans[i]=st.top()-i;
            //push the current element into the stack
            st.push(i);
}
        return ans;
    }
};
