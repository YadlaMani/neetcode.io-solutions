class Solution {
public:
    int find(vector<int>&nums){//similar solution to house robber 1
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
        
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1) take+=prev2;
            int notTake=prev;
            int curr=max(take,notTake);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        //as it is circular array either the first or last element has to be picked
        vector<int>temp1;
        vector<int>temp2;
        for(int i=0;i<nums.size();i++){
            if(i!=0) temp1.push_back(nums[i]);//temp1 array not picking the first element
            if(i!=nums.size()-1) temp2.push_back(nums[i]);//temp2 array not picking the second element
        }
        return max(find(temp1),find(temp2));//finding the maximum in them
    }
};
