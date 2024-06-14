class Solution {
public:
    void getAns(vector<string>&ans,string str,int open,int close){
        //when all the left ( are opened and all the right ) are closed add to the array
        if(open==0&&close==0){
            ans.push_back(str);
        }
        //when there is a open bracket close it and close-1
        if(close>0) getAns(ans,str+")",open,close-1);
        //when there is still open bracket left add it and close +1 
        if(open>0) getAns(ans,str+"(",open-1,close+1);
        
    }
    vector<string> generateParenthesis(int n) {
        //backtracking
        vector<string>ans;
        //string of ans , presnt string,open count,close count
        getAns(ans,"",n,0);
        return ans;
    }
};
