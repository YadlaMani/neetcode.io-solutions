class Solution {
public:
    //function to check if a string is a plaindrome or not
    bool check(string str){
        int l=0;
        int r=str.size()-1;
        while(l<r){
            if(str[l]!=str[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;

    }
    void backTrack(int i,string s,vector<vector<string>>&ans,vector<string>&temp){
        if(i==s.size()){//when we reach to the end of the string push the result to the ans
            ans.push_back(temp);
            return;

        }
        //traverse the string from the given index
        for(int j=i;j<s.size();j++){
            //check each substring
            string sub=s.substr(i,j-i+1);
            //if the substring is palindrome
            if(check(sub)){
                //push to the temp
                temp.push_back(sub);
                //increase the j
                backTrack(j+1,s,ans,temp);
                //remove the temp to continue the recurrsion
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        //use backtracking to solve the problem
        backTrack(0,s,ans,temp);
        return ans;
    }
};
