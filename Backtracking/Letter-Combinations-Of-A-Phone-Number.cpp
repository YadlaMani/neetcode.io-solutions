class Solution {
public:
    const vector<string>pad={
   "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
    };//intialize a vector of strings corresponding the numbers
    void helper(string digits,int i,vector<string>&ans,string temp){
        if(i==digits.size()){//when we reach size of the digits add the temp to the ans
            ans.push_back(temp);
            return;
        }
        int k=(digits[i]-'0')-2;//caculating index for the pad ( ex: 2 -> (2-2)=0)
        for(int j=0;j<pad[k].size();j++){//traversing through all the characters of the string at that index in pad
        //increment the index and add the character to the temp
            helper(digits,i+1,ans,temp+pad[k][j]);

        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits==""){
            return {};
        }//base case
        vector<string>ans;
        string temp="";
        //helper function
        helper(digits,0,ans,temp);
        return ans;


    }
};
