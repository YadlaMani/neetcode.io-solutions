class Solution {
public:
    void helper(vector<int>&nums,int i,vector<vector<int>>&ans,vector<int>&temp){
        if(i==nums.size()){//if we reach size of nums add the temp vector to ans
            ans.push_back(temp);
            return;
        }
        //not picking the current element
        helper(nums,i+1,ans,temp);
        //pushing the current element into temp
        temp.push_back(nums[i]);
       //picking the current element
        helper(nums,i+1,ans,temp);
         temp.pop_back();
        
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;//ans vector
        vector<int>temp;//temp vector to store the current elements in recursion tree
        helper(nums,0,ans,temp);
        return ans;
    }
};
