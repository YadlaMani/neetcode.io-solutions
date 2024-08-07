class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2) return false;//if the sum is odd of the whole array then it can't be divded into two equal halves
        int c=sum/2;
    //intilizing a dp vector to see if we can get the target of sum/2
        vector<vector<bool>>dp(n,vector<bool>(sum/2+1,0));
        for(int i=0;i<n;i++) dp[i][0]=true;
        if(sum/2>=nums[0])
        dp[0][nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int target=1;target<=sum/2;target++){
                bool notTake=dp[i-1][target];
                bool take=false;
                if(nums[i]<=target) take=dp[i-1][target-nums[i]];
                dp[i][target]=take || notTake;
            }
        }
        return dp[n-1][sum/2];
    }
};
