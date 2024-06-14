class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int sum=0;
        stack<int>st;
        for(int i=0;i<tokens.size();i++){
           if(tokens[i]=="*"||tokens[i]=="/"||tokens[i]=="-"||tokens[i]=="%"||tokens[i]=="+"){//when an operator is encountered pop the elements from the stack and perform the operations 
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                char ch=tokens[i][0];
                switch(ch){
                    case '+':st.push(b+a);break;
                    case '-':st.push(b-a);break;
                    case '*':st.push(b*a);break;
                    case '%':st.push(b%a);break;
                    case '/':st.push(b/a);break;
                        
                }
        }
            
        else{//else push the numbers into the stack converting them into numbers
            st.push(stoi(tokens[i]));
        }
        }
        return st.top();
        
    }
};
