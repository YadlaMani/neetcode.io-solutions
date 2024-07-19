class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,0);//initialize a dp array
        dp[0]=cost[0];//first index cost would be cost[0]

        dp[1]=cost[1];//second index cost would be  cost[1]
        for(int i=2;i<n;i++){//move from step 2 to last step caculating the minimum steps and adding the current steps
            dp[i]=min(dp[i-1],dp[i-2])+cost[i];
        }
        return min(dp[n-1],dp[n-2]);
        
    }
};
