class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++){//push the element into the stack when encountered {,[,(
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(s[i]=='('||s[i]=='['||s[i]=='{'){
                    st.push(s[i]);
                }
                else{
                    char ch=st.top();//when other character is encountered we check the top of the stack and check if the top is counter part or not if yes pop that else pop
                    if((s[i]==')' && ch=='(') || (s[i]=='}' && ch=='{') || (s[i]==']' and  ch=='[')){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                    
                }
            }
        }//seeing that entire stack balances or not 
        return st.empty()?true:false;
    }
};
