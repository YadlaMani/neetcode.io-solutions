class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>lArray(n);
        vector<int>rArray(n);
        lArray[0]=1;
        //getting the left product
        for(int i=0;i<n-1;i++){
            lArray[i+1]=lArray[i]*nums[i];
        }
        //getting the right product
        rArray[n-1]=1;
        for(int i=n-1;i>0;i--){
            rArray[i-1]=rArray[i]*nums[i];
        }
        //multiplying both arrays
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(lArray[i]*rArray[i]);
        }
        return ans;
        
    }
};
