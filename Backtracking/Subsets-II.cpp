class Solution {
public:
    void backTrack(vector<int>&nums,int i,vector<vector<int>>&ans,vector<int>&temp){
        //push the current recurrsion element
        ans.push_back(temp);
        for(int j=i;j<nums.size();j++){//traverse the nums
            //check for the duplicate values and index
            if(j!=i && nums[j]==nums[j-1]) continue;
            //else push the new element into the temp
            temp.push_back(nums[j]);
            //backtrack the solution
            backTrack(nums,j+1,ans,temp);
            //remove the element from the temp
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;//current array in the recurrsion tree
        sort(nums.begin(),nums.end());//sort the elements
        //use backtracking
        backTrack(nums,0,ans,temp);
        return ans;
    }
};
