class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        //set doesn't store duplicates
        set<int>ans;
        for(int i=0;i<n;i++){
            //insert elements into the set
            ans.insert(nums[i]);
        }
        return ans.size()!=nums.size();//if set size not equal to nums size the nums contains duplicates
    }
};
