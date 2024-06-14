class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());//sort the array
        vector<vector<int>>ans;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(i>0 and nums[i]==nums[i-1]){//check for duplicates at the first position
                continue;
            }
            int l=i+1,r=n-1;
            
            while(l<r){//visit 2sum problem part 2 for better understanding in leetcode
               
                int sum=nums[i]+nums[l]+nums[r];
                
                if(sum>0){
                    r--;
}
                else if(sum<0){
                    l++;
                }
                else{
                   
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;//after finding the pair make sure to go for the next combination without any duplicates
                    while(nums[l]==nums[l-1] and l<r){
                        l++;
                    }
                }
            }
        }
        return ans;
    }
};
