class Solution {
public:
    int maxProfit(vector<int>& prices) {//Sliding window
        int n=prices.size();
       int l=prices[0];//start with the first index price
        
        int ans=0;
        for(int i=1;i<n;i++){
            if(prices[i]>l){//if you encounter price greater than the l than calculate max
                ans=max(ans,prices[i]-l);
            }
            else{//if you encounter pirce less than l than make l that value
                l=prices[i];
            }
        }
        
        return ans;
    
    }
};
