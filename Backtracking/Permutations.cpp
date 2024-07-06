class Solution {
public:
    void backTrack(vector<int>&nums,int i,vector<vector<int>>&ans){
        //when we done swapping all array add that array to the ans
        if(i==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            //swapping the elements
            swap(nums[i],nums[j]);
            //inncreasing the count and continuing the backtracking
            backTrack(nums,i+1,ans);
            //reswapping the elements
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        //store the answer in the vector
        vector<vector<int>>ans;
        //use backTracking
        backTrack(nums,0,ans);
        return ans;
    }
};
