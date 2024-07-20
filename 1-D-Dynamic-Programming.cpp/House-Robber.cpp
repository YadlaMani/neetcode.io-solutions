class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);//create a dp of size n
        dp[0]=nums[0];//base condition
        for(int i=1;i<n;i++){
            int take=nums[i];//taking the number 
            if(i>1) take+=dp[i-2];//if we take a number than we have to check the previous
            int notTake=dp[i-1];//if we not take the element just check the previous
            dp[i]=max(take,notTake);//maximum of those 2
        }
        return dp[n-1];
    }
};
